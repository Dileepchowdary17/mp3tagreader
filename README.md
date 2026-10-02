MP3 Tag Reader

A command-line based MP3 metadata editor developed in C for reading and modifying ID3v2.3 metadata stored inside MP3 files. The application provides separate operations for viewing and editing metadata such as title, artist, album, year, genre, and comments. It demonstrates practical implementation of C file handling, binary data processing, command-line arguments, dynamic memory allocation, string manipulation, and byte-level metadata processing.

Features

View Metadata — Read and display ID3v2.3 metadata stored in an MP3 file.

Edit Title — Modify the title (TIT2) metadata of an MP3 file.

Edit Artist — Modify the artist (TPE1) metadata.

Edit Album — Modify the album (TALB) metadata.

Edit Year — Modify the release year (TYER) metadata.

Edit Genre — Modify the genre (TCON) metadata.

Edit Comments — Modify the comments (COMM) metadata.

MP3 Validation — Validate the input file extension before performing operations.

ID3v2.3 Frame Processing — Identify metadata using standard ID3v2.3 frame identifiers.

Binary File Handling — Read and modify MP3 metadata using binary file operations.

Temporary File Processing — Use a temporary MP3 file during editing to preserve the remaining file contents.

Command-Line Interface — Perform all operations directly through terminal commands without requiring a graphical interface.

Project Structure
MP3_Tag_Editor/
│
├── main.c              # Program entry point and command-line argument handling
├── view.c              # MP3 metadata reading and display implementation
├── view.h              # View module function declarations
├── edit.c              # MP3 metadata editing implementation
├── edit.h              # Edit module function declarations
├── sample.mp3          # Sample MP3 file used for testing
└── README.md           # Project documentation
Requirements
GCC or any standard C compiler
Linux, macOS, or Windows
Terminal or Command Prompt
Basic C development environment
An MP3 file containing ID3v2.3 metadata

No external libraries or third-party dependencies are required.

File Description
File	Description
main.c	Program entry point. Handles command-line arguments, validates the requested operation, and calls the appropriate view or edit function.
view.c	Implements MP3 metadata reading, ID3 header processing, frame identification, frame-size conversion, and metadata display.
view.h	Contains function declarations required by the metadata viewing module.
edit.c	Implements metadata editing by locating the selected ID3v2.3 frame, replacing its data, and reconstructing the MP3 file.
edit.h	Contains function declarations required by the metadata editing module.
sample.mp3	Sample MP3 file used to test metadata viewing and editing operations.
README.md	Contains project documentation, usage instructions, implementation details, and examples.
Application Flow
View Metadata

The view operation reads the metadata directly from the MP3 file without modifying the original file.

Start
  |
  v
Read Command-Line Arguments
  |
  v
Check View Operation (-v)
  |
  v
Validate MP3 File
  |
  v
Open MP3 in Binary Read Mode
  |
  v
Read ID3 Header
  |
  v
Verify ID3 Tag
  |
  v
Read ID3v2.3 Version
  |
  v
Read Metadata Frames
  |
  v
Identify Frame IDs
  |
  +----> TIT2 → Title
  |
  +----> TPE1 → Artist
  |
  +----> TALB → Album
  |
  +----> TYER → Year
  |
  +----> TCON → Genre
  |
  +----> COMM → Comments
  |
  v
Display Metadata
  |
  v
Close File
  |
  v
End
Edit Metadata

The edit operation creates a temporary file, copies the original MP3 data while replacing the selected metadata frame, and then replaces the original file.

Start
  |
  v
Read Command-Line Arguments
  |
  v
Check Edit Operation (-e)
  |
  v
Validate MP3 File and Arguments
  |
  v
Identify Selected Metadata Option
  |
  v
Open Original MP3
  |
  v
Create Temporary MP3 File
  |
  v
Read ID3 Header
  |
  v
Read Metadata Frames
  |
  v
Find Selected Frame
  |
  v
Replace Frame Data
  |
  v
Write Updated Frame
  |
  v
Copy Remaining MP3 Data
  |
  v
Close Files
  |
  v
Replace Original MP3
  |
  v
Display Success Message
  |
  v
End
Supported Metadata

The application supports the following ID3v2.3 metadata frames:

Command Option	ID3v2.3 Frame	Metadata
-t	TIT2	Title
-a	TPE1	Artist
-A	TALB	Album
-y	TYER	Year
-g	TCON	Genre
-c	COMM	Comments

The frame identifier is used internally to locate the corresponding metadata inside the MP3 file.

For example:

TIT2 → Title
TPE1 → Artist
TALB → Album
TYER → Year
TCON → Genre
COMM → Comments
Compilation

Navigate to the project directory:

cd MP3_Tag_Editor

Compile all source files using GCC:

gcc main.c view.c edit.c -o mp3tag

For compilation with warnings enabled:

gcc -Wall -Wextra main.c view.c edit.c -o mp3tag

After successful compilation, the executable mp3tag will be generated.

Execution
Linux / macOS
./mp3tag -v sample.mp3
Windows
mp3tag.exe -v sample.mp3
Usage

The application supports two primary operations:

-v    View MP3 metadata
-e    Edit MP3 metadata
1. View MP3 Metadata
Command
./mp3tag -v sample.mp3
Input

The user provides:

-v → View operation
sample.mp3 → MP3 file to be analyzed
Processing

The application:

Validates the MP3 file.
Opens the file in binary read mode.
Reads the ID3 header.
Verifies the ID3 tag.
Reads the ID3v2.3 version.
Processes the metadata frames.
Identifies supported frame IDs.
Extracts and displays the corresponding metadata.
Example Output
ID3 version : 2.3.0
Title       : Baagundu Po
Artist      : Sai Abhyankkar, Sanjith Hegde
Album       : Dude
Year        : 2025
Genre       : Sad
Comments    : Banger

The view operation does not modify the MP3 file.

2. Edit MP3 Metadata

The edit operation uses the following command structure:

./mp3tag -e <option> "<new value>" sample.mp3

Where:

-e          → Edit operation
<option>    → Metadata field to modify
<new value> → New metadata value
sample.mp3  → Target MP3 file
Edit Title
Command
./mp3tag -e -t "New Title" sample.mp3
Operation

The application locates the TIT2 frame and replaces its existing title with the supplied value.

Example
Before:
Title : Baagundu Po

Command:
./mp3tag -e -t "New Title" sample.mp3

After:
Title : New Title
Edit Artist
Command
./mp3tag -e -a "Artist Name" sample.mp3
Operation

The application locates the TPE1 frame and updates the artist metadata.

Example
Before:
Artist : Sai Abhyankkar

Command:
./mp3tag -e -a "Artist Name" sample.mp3

After:
Artist : Artist Name
Edit Album
Command
./mp3tag -e -A "Album Name" sample.mp3
Operation

The application locates the TALB frame and replaces the existing album information.

Edit Year
Command
./mp3tag -e -y "2026" sample.mp3
Operation

The application locates the TYER frame and updates the stored release year.

Example
Before:
Year : 2025

Command:
./mp3tag -e -y "2026" sample.mp3

After:
Year : 2026
Edit Genre
Command
./mp3tag -e -g "Rock" sample.mp3
Operation

The application locates the TCON frame and updates the genre metadata.

Example
Before:
Genre : Sad

Command:
./mp3tag -e -g "Rock" sample.mp3

After:
Genre : Rock
Edit Comments
Command
./mp3tag -e -c "My Comment" sample.mp3
Operation

The application locates the COMM frame and updates the comment metadata.

Example
Before:
Comments : Banger

Command:
./mp3tag -e -c "My Comment" sample.mp3

After:
Comments : My Comment
Data Storage

The project does not use a separate database or text file for storing metadata.

Instead, the metadata is stored directly inside the ID3v2.3 section of the MP3 file.

The general structure is:

MP3 File
   |
   +-- ID3 Header
   |
   +-- TIT2  --> Title
   |
   +-- TPE1  --> Artist
   |
   +-- TALB  --> Album
   |
   +-- TYER  --> Year
   |
   +-- TCON  --> Genre
   |
   +-- COMM  --> Comments
   |
   +-- Other ID3 Frames
   |
   +-- MP3 Audio Data
ID3v2.3 Frame Structure

Each ID3v2.3 frame contains a frame identifier, frame size, flags, and frame data.

+----------+------------+-------+-------------+
| Frame ID | Frame Size | Flags | Frame Data  |
+----------+------------+-------+-------------+
| 4 bytes  | 4 bytes    | 2 bytes | Variable |
+----------+------------+-------+-------------+

For example, a title frame is represented as:

TIT2
 |
 +-- Frame Size
 |
 +-- Flags
 |
 +-- Encoding
 |
 +-- Title Data

The application reads these fields using binary file operations and identifies the metadata based on the four-character frame identifier.

Metadata Editing Procedure

When a metadata field is edited, the original MP3 is not directly overwritten during the frame-processing stage.

The application follows this procedure:

Original MP3
     |
     v
Open Original File
     |
     v
Create Temporary MP3
     |
     v
Copy ID3 Header
     |
     v
Read Each Metadata Frame
     |
     v
Is This the Selected Frame?
     |
   /   \
 Yes    No
 |       |
 v       v
Replace  Copy
Frame    Existing
 |       |
  \      /
   \    /
    v  v
Copy Remaining MP3 Data
     |
     v
Close Files
     |
     v
Remove Original File
     |
     v
Rename Temporary File
     |
     v
Updated MP3

This approach allows the application to reconstruct the MP3 while replacing only the selected metadata.

Binary File Processing

MP3 files contain binary data, so the application uses binary file modes when processing the file.

Important file-handling functions used in the project include:

fopen()
fread()
fwrite()
fseek()
fclose()
fgetc()
fputc()

These functions allow the application to:

Open MP3 files
Read ID3 headers
Read metadata frame identifiers
Read frame sizes
Read frame data
Write modified metadata
Copy remaining MP3 data
Navigate through the file
Close files safely
Big-Endian Frame Size Processing

ID3v2.3 frame sizes are stored using multiple bytes.

The application converts the four-byte frame size into an integer before reading the corresponding frame data.

Conceptually:

Byte 0 → Shift 24 bits
Byte 1 → Shift 16 bits
Byte 2 → Shift 8 bits
Byte 3 → No shift
          |
          v
     Combine bytes
          |
          v
    Frame Size Integer

This allows the program to determine exactly how many bytes belong to each metadata frame.

During editing, the updated frame size is converted back into the required byte representation before being written to the MP3 file.

Input Validation

Before processing an MP3 file, the application validates the command-line input.

For example:

./mp3tag -v sample.mp3

The application checks whether the supplied file has the expected .mp3 extension.

For editing:

./mp3tag -e -t "New Title" sample.mp3

The application validates:

Operation type
Metadata option
New metadata value
MP3 file name

Invalid input results in an appropriate error message instead of continuing with the operation.

Error Handling

The application performs basic error handling for situations such as:

Invalid command-line arguments
Invalid MP3 file extension
Unable to open the MP3 file
Missing ID3 tag
Unable to create the temporary file
Memory allocation failure
Unsupported metadata option

Example:

Error: It's not an mp3 file

or:

Invalid Input
Concepts Used

This project demonstrates practical implementation of the following C programming and systems-level concepts:

C programming
Command-line arguments
File handling
Binary file I/O
Pointers
Character arrays
Strings
String comparison
Dynamic memory allocation
malloc() and free()
fopen() and fclose()
fread() and fwrite()
fseek()
fgetc() and fputc()
Bitwise operators
Byte manipulation
Big-endian data conversion
ID3v2.3 frame processing
Modular programming
Header files
Temporary file handling
Input validation
Error handling
Testing

The application can be tested using a sample MP3 file.

View Test
./mp3tag -v sample.mp3

Verify that the expected metadata is displayed.

Edit Test

For example:

./mp3tag -e -t "Test Title" sample.mp3

Then verify the updated metadata:

./mp3tag -v sample.mp3

Expected result:

Title       : Test Title

The same procedure can be followed for artist, album, year, genre, and comments.

Example Complete Workflow
1. Compile the project
       |
       v
2. Run the application
       |
       v
3. View existing metadata
       |
       v
4. Select the metadata field to modify
       |
       v
5. Provide the new value
       |
       v
6. Application validates the input
       |
       v
7. Application locates the corresponding ID3v2.3 frame
       |
       v
8. Application creates a temporary MP3 file
       |
       v
9. Selected metadata is replaced
       |
       v
10. Remaining MP3 data is copied
       |
       v
11. Temporary file replaces the original file
       |
       v
12. View the MP3 again to verify the modification

Example Session
$ gcc -Wall -Wextra main.c view.c edit.c -o mp3tag

$ ./mp3tag -v sample.mp3

ID3 version : 2.3.0
Title       : Baagundu Po
Artist      : Sai Abhyankkar, Sanjith Hegde
Album       : Dude
Year        : 2025
Genre       : Sad
Comments    : Banger

Update the title:

$ ./mp3tag -e -t "New Title" sample.mp3

Tag Edited Successfully

Verify the modification:

$ ./mp3tag -v sample.mp3

ID3 version : 2.3.0
Title       : New Title
Artist      : Sai Abhyankkar, Sanjith Hegde
Album       : Dude
Year        : 2025
Genre       : Sad
Comments    : Banger

Limitations
The current implementation is designed specifically for ID3v2.3 metadata.
The application is command-line based.
MP3 files without compatible ID3 metadata may not provide the expected tags.
Metadata frame formats such as COMM require more specialized parsing than simple text frames.
The project is intended primarily for learning and demonstrating C-based binary file processing and metadata manipulation.
Author

Manubolu Dileepchowdary
