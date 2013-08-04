#!/usr/bin/perl
use strict;
use warnings;

use Getopt::Std;

my %options = ();
getopts("ab:cd:e:", \%options);

print "-a $options{a}\n" if defined $options{a};
print "-b $options{b}\n" if defined $options{b};
print "-c $options{c}\n" if defined $options{c};
print "-d $options{d}\n" if defined $options{d};
print "-e $options{e}\n" if defined $options{e};

if ($options{a}) {
    &show_help();
}

sub show_help {
    print "show help\n";
}

