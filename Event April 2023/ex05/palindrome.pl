use strict;
use warnings;

print "Enter a string: ";
my $input = <STDIN>;

# Removes the newline character from the end of the string
chomp($input);

# lc converts string to lowercase
if (lc(reverse($input)) eq lc($input)){
    print "The string is a palindrome!\n";
} else {
    print "The string is not a palindrome.\n";
}