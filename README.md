# simple-search-engine
**Build a simple Search Engine which allow user to use keyword to search for result**

## General idea
There is a database (.txt file) which allow user to import some data and export data as needed.

## Log
*July 19th, 2021:*
### Work
Importing functionality works fine, user can type keyword then the keyword and a number will import into the keyword.txt. 
### Need to solve
check the existing keyword in the keyword.txt, if it's there, update database.txt if user want. If it's not there, import new data and update the number of data for that keyword

*July 24th, 2021:*
### Work
It's able to access the existed word in the keyword.txt and output its corresponding result from database.txt. 
### Need to solve
Add a result to a new keyword will replace all the data in the database.txt

*July 27th, 2021:*
### Work
It's successful to add new information instead of replacing exsited information in database.txt. 
### Need to solve
After adding three different keywords, there should have threee different words in the keyword.txt. However, it's currently has one word repeat twice.

*July 28th, 2021:*
### Work
fix the problem of adding keyword to the keyword.tx without duplicating. 
fix the problem that reading keyword and information dowesn't work correctly (reason: some thing wrong with the size/index of vectors)
### Need to solve
New information doesn't appear in the database.txt

*July 29th, 2021:*
### Work
update the number of information of a keyword and add information to the databasse.txt based on the index (resolved method: use list to copy the vector, insert element then copy back to vector)
### Need to solve
try to beautify the interface (new knowledge that didn't learn yet)

*August 16th, 2021:*
### Work
start working on building network which can allow multiple clients connect with server