#!/usr/bin/env perl
use strict;
use warnings;

use Term::ANSIColor;

my $num = scalar(@ARGV);

if ( $num == 1 
        && $ARGV[0] =~ m/^[1-9]\d*$/i ) {
    &factorial($ARGV[0]);
} else {
    print color("red");
    print "Please input a positive integer.\n";
    print color("reset");
}

sub factorial {
    my ($number) = @_;
    my $fac = 1;
    foreach my $i ( 2..$number ) {
        $fac *= $i;
    }
    if ( $fac ne "inf") {
        printf "The result is: $fac\n";
        if ( $fac =~ m/[1-9]\d*[1-9]+(0+)/i ) {
            print color("green");
            my $count = rindex($1.'#', '#');
            print "There are $count zoro in the end of the result.\n";
            print color("reset");
        } else {
            print color("red");
            print "The result does not have zero in the end.\n";
            print color("reset");
        }
    } else {
        print color("red");
        print "The result is infinity\n";
        print color("reset");
    }
}
