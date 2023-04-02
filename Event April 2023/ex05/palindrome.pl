#!/usr/bin/perl
use strict;
use warnings;

print "Enter a string: ";
my $input = <STDIN>;
chomp($input);

if (lc(reverse($input)) eq lc($input)) {
    print "The string is a palindrome!\n";
} else {
    print "The string is not a palindrome.\n";
}