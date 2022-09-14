#include <iostream>
#include "bst.cpp"  // Including the CPP file is intentional for simplicity.
#include "directory.h"

using namespace std;

/* TODO:

   You must complete or alter the following functions. They are listed in the
   order you should complete them:

   * make_directory: depends on updating BST::insert to return a bool (note:
     you will not receive any partial points until you also have list_directory
     working)

   * list_directory: depends on writing BST::sorted_output (almost all the
     tests depend on this working properly so complete this ASAP)

   * change_directory: depends on updating BST::contains to return type
     BinaryNode<T>*, rather than bool

   * output_pwd: depends on change_directory working properly

   * remove_directory: depends on writing BST::remove
*/


/* Attempt to update cwd_ptr to point to a subdirectory of the previous cwd.

   If `name` is `..` change into the parent directory. Attempting to change to
   the parent directory of the root should produce the "Invalid Directory:
   <NAME>" error message.

   cwd_ptr should only be updated if the current directory contains a directory
   with the name `name`, otherwise the message "Invalid directory: <NAME>"
   should be output where `<NAME>` is replaced by the `name` variable.

   `cwd_ptr` is a pointer to a pointer to a Directory. It is passed in this way
   so we can change the value of the pointer in the calling function (modify
   the value of cwd in main).

   For instance if we wanted to update cwd to point to some directory `foo` we
   might do:

   Directory &foo = some_function_that_returns_a_directory_reference();
   *cwd_ptr = &foo;
*/
void change_directory(Directory **cwd_ptr, string name) {
  // We need to create a dummy Directory object to use for comparison. Recall
  // that only the name is used when comparing Directory instances.
  Directory dummy(name);
  /* TODO:
     * If name is .. change into the parent directory or output message
     * See if dummy is contained in the subdir BST of cwd
     * Update the cwd if it is otherwise output the message.
   */
  cout << "Invalid directory: " << name << endl;
}


/* Output the contents of the directory in a sorted manner.

   If a directory contains the subdirectories pear, apple, banana, orange it's
   output should be exactly `apple banana orange pear \n` less the surrounding
   '`'. Note the space after the last subdirectory name and the trailing
   newline.`

   There should be no output is the directory has no subdirectories.
 */
void list_directory(Directory *cwd) {
  /* TODO:
       Replace `stack_output` with `sorted_output` when you feel your
       sorted_output function works.
  */
  cwd->get_subdirs()->stack_output();
}

/* Attempt to create a directory with name `name` under the cwd.

   On failure (the directory already exists) output: "Directory already exists:
   <NAME>" where `<NAME>` is replaced by the `name` variable.
*/
void make_directory(Directory *cwd, string name) {
  /* TODO:
       Create a new directory and add it to the subdirectory BST of `cwd`

     WARNING: Be sure to not leak any memory if the directory cannot be added.
   */
  if (name == "..") {
    cout << ".. is a reserved directory name\n";
    return;
  }
  cout << "Directory already exists: " << name << endl;
}

/* Output the complete path to the present working directory.

   From the root the output should only be `/\n` less the surrounding ticks.

   From a directory foo with parent bar whose parent is the root the output
   should be `/bar/foo\n`

   Hint: You might want to use one of the data structures to help produce the
   output in the correct order.
*/
void output_pwd(Directory *cwd) {
  // TODO: Produce the correct output
  cout << "/\n";
}

/* Attempt to remove a directory with name `name` from the cwd.

   If the directory does not exist output: Invalid directory: <NAME>

 */
void remove_directory(Directory *cwd, string name) {
  // We need to create a dummy Directory object to use for comparison. Recall
  // that only the name is used when comparing Directory instances.
  Directory dummy(name);
  /* TODO:
     * Attempt to remove the directory from the BST
     * If it is removed you need to delete the Directory object
     * If it is not, output the error message (you need a try/catch block)

     Example of how to delete a Directory&:

     Directory &tmp = some_function_that_returns_a_directory_reference();
     delete &tmp;

     Example of catching exceptions

     try {
         some_function_that_may_throw_an_integer();
     }
     catch (int) {
         // do something else when it fails
     }
   */
  cout << "Invalid directory: " << name << endl;
}


/* The main program simply prompts the user for commands until the input stream
   is closed (ctrl+d or EOF).

   You need not change anything in main. However, feel free to add additional
   commands for fun and possibly  extra credit.
 */
int main() {
  Directory root("");
  Directory *cwd = &root;
  string command;

  while (cin) {
    cout << cwd->get_name() << "> ";
    getline(cin, command);
    if (command == "help") {
      cout << "Commands: cd NAME, mkdir NAME, ls, pwd, rmdir NAME\n";
    }
    else if (command.substr(0, 3) == "cd ") {
      change_directory(&cwd, command.substr(3, command.size()));
    }
    else if (command == "ls") {
      list_directory(cwd);
    }
    else if (command.substr(0, 6) == "mkdir ") {
      make_directory(cwd, command.substr(6, command.size()));
    }
    else if (command == "pwd") {
      output_pwd(cwd);
    }
    else if (command.substr(0, 6) == "rmdir ") {
      remove_directory(cwd, command.substr(6, command.size()));
    }
    else if (command == ""); // Do nothing when there is no input
    else {
      cout << "Invalid command. Type help for the list of commands.\n";
    }
  }
  return 0;
}
