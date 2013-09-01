#!/usr/bin/perl
use strict;
use warnings;

use DBI;

my $db = "test";
my $user = "bj";
my $pass = "s3kr1t";
my $host = "localhost";

my $query = "show tables";

my $dbh = DBI->connect("DBI:mysql:$db:$host", $user, $pass);

my $sqlQuery = $dbh->prepare($query) or die "Error";

my $rv = $sqlQuery->execute or die "Error";

while (my @row = $sqlQuery->fetchrow_array()) {
    my $tables = $row[0];
    print "$tables\n";
}

my $rc = $sqlQuery->finish;
exit(0);
