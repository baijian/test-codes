#!/usr/bin/perl
use strict;
use warnings;

use Getopt::Long;

my ($name, $age, $employed, $help);

GetOptions (
    'name=s' => \$name,
    'age=i' => \$age,
    'employed!' => \$employed,
    'help|h!' => \$help,
);

if ($help) {
    print "help\n";
}
