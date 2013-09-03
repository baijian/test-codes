#!/usr/bin/evn perl
use strict;
use warnings;

use Net::FTP;
use DBI;

my($sec, $min, $hour, $mday, $mon, $year, $wday, $yday) = localtime(time);
$year += 1900;
$mon++;
$mon = '0'.$mon if length($mon) < 2;
$mday = '0'.$mday if length($mday) < 2;
my $logtime = $year."-".$mon."-".$mday." ".$hour.":".$min.":".$sec;

#read config
my $host;
my $username;
my $password;
my $basedir;
my $filename;
my $dbname;
my $dbuser;
my $dbpassword;
my $dbhost;
open CONF, "ftp.config" or die "$logtime Can not open config file!\n";
while (<CONF>) {
    chomp($_);
    if (length($_) > 1) {
        my ($key, $val) = split(/=/, $_);
        $host = $val if ($key eq "host");
        $username = $val if ($key eq "username");
        $password = $val if ($key eq "password");
        $basedir = $val if ($key eq "loc");
        $filename = $val if ($key eq "filename");
        $dbname = $val if ($key eq "dbname");
        $dbuser = $val if ($key eq "dbuser");
        $dbpassword = $val if ($key eq "dbpassword");
        $dbhost = $val if ($key eq "dbhost");
    }
}
close CONF;

#new a ftp client
my $ftp = Net::FTP->new(
    $host,
    Timeout => 30,
    Debug => 0,
) or die "Could not connect.\n";
$ftp->login($username, $password) or die "$logtime Could not login.\n", $ftp->message;

#get notify flag file of today
my $dir = "$year$mon$mday";
$ftp->cwd("$basedir");
my $remotefile = $basedir.$dir."/".$filename;
my $localnotify = "notify-$year$mon$mday.flag";
unlink $localnotify;
$ftp->get($remotefile, $localnotify) or die "$logtime Could not get file-> $remotefile .\n";

#today history notify file
my $notify = "notify/$localnotify";
my @files;
if ( -e $notify ) {
    print "$logtime Exists notify of today\n";
    open NOTIFY, $notify or die "$logtime Open notify file Error";
    while(my $line = <NOTIFY>) {
        chomp($line);
        my($filedate, $filetime, $flag, $filename) = split(/ /, $line);
        open NEW, $localnotify or die "$logtime Open local notify file Error";
        while (my $line2 = <NEW>) {
            chomp($line2);
            my($new_filedate, $new_filetime, $new_flag, $new_filename) = split(/ /, $line2);
            if (($new_filename eq $filename) and $filetime ne $new_filetime) {
                print "$logtime Reupdate data -> $filename\n";
                push(@files, $filename);
                last;
            }
        }
        close NEW;
    }
    close NOTIFY;
} else {
    print "$logtime First notify\n";
    system "mv", "$localnotify", "notify/";
    open NOTIFY, "notify/$localnotify" or die "$logtime Open notify file Error";
    while (<NOTIFY>) {
        chomp($_);
        my($filedate, $filetime, $flag, $filename) = split(/ /, $_);
        push(@files, $filename);
    }
    close NOTIFY;
}

#rsync data
if (@files) {
    print "$logtime Update data.\n";
    foreach (@files) {
        my @d = split(/\//, $_);
        my $data_filename = "data/madata-".$d[4].".gz";
        $ftp->get($_, $data_filename);
        my @ARGV;
        push(@ARGV, $data_filename);
        system "gzip", "-d", @ARGV;
        my $y = substr $d[4], 0, 4;
        my $m = substr $d[4], 4, 2;
        my $d = substr $d[4], 6, 2;
        my $begin = $y."-".$m."-".$d." 00:00:00";
        my $end = $y."-".$m."-".$d." 23:59:59";
        my $sql = "delete from etl_ma_co_data where stat_date >= '$begin' and stat_date <= '$end'";
        my $dsn = "DBI:mysql:$dbname:$dbhost;mysql_local_infile=1";
        my $dbh = DBI->connect($dsn, $dbuser, $dbpassword);
        my $sqlQuery = $dbh->prepare($sql) or die "$logtime Prepare sql statement Error";
        my $rc = $sqlQuery->execute or die "$logtime Execute sql Error";
        my $data_filename_after_gzip = "data/madata-".$d[4];
        $sql = "LOAD DATA LOCAL INFILE '$data_filename_after_gzip' INTO TABLE etl_ma_co_data".
                " FIELDS TERMINATED BY '\t' LINES TERMINATED BY '\n'".
                " (stat_date, channel_id, channel_name, reg_num, reg_num_xh,".
                " login_ratio_one, login_ratio_seven, payrate, arpu)";
        $sqlQuery = $dbh->prepare($sql) or die "$logtime Prepare sql statement Error";
        $rc = $sqlQuery->execute or die "$logtime Execute sql Error";
        print $rc;
    }
}
if ( -e $localnotify ) {
    unlink $localnotify;
}
$ftp->quit;

