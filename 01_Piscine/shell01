# ex01
// use groups to list the user, groups $FT_USER only display the list, need to use ',' to separate
// groups - print the groups a user is in
// use tr to replace ' ' with ','
// tr - translate or delete characters


groups $FT_USER | tr ' ' ','

# ex02
// man find
// find . is to fnd docs from the current directories
// f: to find regular files
// type for file type
// -exec in the find command: execute a command on each file or directory that matches the search criteria specified by the other options.
// basename: a utility used to extract the base file name from a given path. It removes the directory path, leaving only the final component of the file name. Additionally, it can also remove a specified suffix (such as a file extension) from the file name.


find . -type f -name "*.sh" -exec basename {} .sh \;

# ex03
// find . to find in current dir
// wc (word count) print newline, word, and byte counts for each fle
// wc -l only prints the newline counts

find . | wc -l

# ex04
// mac address: media access control address, a 12-digit hexadecimal number assigned to each device connected to the network.
// mac address belong to the data link layer of the Open System Interconnection
// ref link: https://medium.com/@lakshanmamalgaha/what-is-a-mac-address-and-why-you-should-know-about-it-9f970b3ba3fd
// ifconfig -a : display all interfaces which are currently available, even if down
// grep: used to search text within files
// awk: for text processing, pattern matching
//

ifconfig -a | grep ether | awk '{print $2 "\n"}'

# ex05
file name: "\?$*'MaRViN'*$?\"

// touch: to create file
/* 
    Double Quotes ("): Escaped as \" to include them in the filename.
    Single Quotes ('): Escaped as \' to include them in the filename.
    Dollar Sign ($): Escaped as \$ to prevent it from being interpreted as a variable.
    Question Mark (?) and Asterisk (*): Escaped as \? and \* to prevent filename expansion.
    Backslash (\): Use \\ to represent a single backslash.
*/

touch \"\\\?\$\*'MaRViN'\*\$\?\\\"

