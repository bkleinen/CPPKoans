C++ Koans

ABOUT
=====

Inspired by the Edge Case Ruby Koans ( http://rubykoans.com/ ) 
I wanted to create something similar for the C++ Language.

The basic idea is to learn a language by unit tests, reading code and
solving little puzzles filling in resulting values in empty spaces.
If all expectations are correct, no output is produced, otherwise
a message is printed.

Of course C++ doesn't lend itself to the approach used in the 
ruby koans, making heavy use of reflection and the dynamic aspects
of the ruby language. Also, I wanted a single place to put notes 
about language and syntax specifics, to be able to look it up quickly. 

Therefore, the C++ Koans are much more simple in structure and contain
basic content as well (as, e.g., control structures which are not at all
surprising). Also, I skipped the whole reflection part. There is a main
that calls all the meditate functions of all Koan classes, and all single 
Koans in a class are called via this function. To check that I haven't 
forgotten anything there's a little ruby script scripts/check_all_called.rb
which does exactly that. Although this simple structure might not be as
elegant as the ruby Koans or even as it could be within C++, I preferred it
as it is easy understandable by a C++ beginner.

USAGE
=====

Just check out the master branch, run CPPKoans.cpp and start filling out the 
empty spaces ( marked with _____ ) with the correct values. You can choose
if all koans should be run or if the program should terminate at the first
unmet expectation by setting QUIT_ON_UNMET_EXPECTATION in StopMeditating.h.
If you want to change the order of the koans or just pick
some, rearrange or comment them out in the main function.

ADDING NEW KOANS
================
There are two branches in the repository: master and development. 
The master branch contains the empty spaces to fill in, the development branch
contains the solutions. If you add koans, it is easier to do so in the development 
branch, merge the changes to master and then run scripts/replace_expectations.rb
to replace the values with the _____ placeholder.

If you want to help develop them further, feel free to contact me at
kleinen@infrastructure.de or send me a pull request.

Barbara Kleinen, March 2012