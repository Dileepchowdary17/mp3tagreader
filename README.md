MP3 Tag Reader

A simple command-line MP3 metadata editor written in C. It allows users to view and edit ID3v2.3 tags such as title, artist, album, year, genre, and comments using binary file handling and command-line arguments.

Features

View Metadata — Display ID3v2.3 metadata stored in an MP3 file

Edit Title — Update the title of the MP3 file

Edit Artist — Update the artist name

Edit Album — Update the album name

Edit Year — Update the release year

Edit Genre — Update the genre

Edit Comments — Update the comment field

MP3 Validation — Validate the input file before processing

Binary File Handling — Read and modify MP3 metadata at the byte level

Project Structure
MP3_Tag_Editor/
├── main.c              # Program entry point and command-line handling
├── view.c              # MP3 metadata reading and display operations
├── view.h              # View function declarations
├── edit.c              # MP3 metadata editing operations
├── edit.h              # Edit function declarations
├── sample.mp3          # Sample MP3 file for testing
└── README.md           # Project documentation
Requirements
GCC or another C compiler
Linux, macOS, or Windows with a C development environment
Terminal or Command Prompt
An MP3 file containing ID3v2.3 metadata
File Description
File	Description
main.c	Program entry point, argument handling, and operation selection
view.c	Reads and displays ID3v2.3 metadata from MP3 files
view.h	Function declarations used by the view module
edit.c	Locates and modifies metadata frames in MP3 files
edit.h	Function declarations used by the edit module
sample.mp3	Sample MP3 file used for testing
README.md	Project documentation
Application Flow
View Metadata
Start
  |
  v
Read Command-Line Arguments
  |
  v
Validate MP3 File
  |
  v
Open MP3 File
  |
  v
Read ID3 Header
  |
  v
Read Metadata Frames
  |
  v
Identify Required Tags
  |
  v
Display Metadata
  |
  v
End
Edit Metadata
Start
  |
  v
Read Command-Line Arguments
  |
  v
Validate Input
  |
  v
Open Original MP3
  |
  v
Create Temporary File
  |
  v
Read ID3 Frames
  |
  v
Find Selected Frame
  |
  v
Replace Metadata
  |
  v
Copy Remaining MP3 Data
  |
  v
Replace Original File
  |
  v
End
Supported Metadata

The application works with the following ID3v2.3 frame identifiers:

Option	Frame ID	Metadata
-t	TIT2	Title
-a	TPE1	Artist
-A	TALB	Album
-y	TYER	Year
-g	TCON	Genre
-c	COMM	Comments
Compilation

Compile all source files using GCC:

gcc main.c view.c edit.c -o mp3tag

For compilation with warnings enabled:

gcc -Wall -Wextra main.c view.c edit.c -o mp3tag
Execution
Linux / macOS
./mp3tag -v sample.mp3
Windows
mp3tag.exe -v sample.mp3
Usage
View MP3 Metadata
./mp3tag -v sample.mp3

Example:

ID3 version : 2.3.0
Title       : Baagundu Po
Artist      : Sai Abhyankkar, Sanjith Hegde
Album       : Dude
Year        : 2025
Genre       : Sad
Comments    : Banger
Edit Title
./mp3tag -e -t "New Title" sample.mp3
Edit Year
./mp3tag -e -y "2026" sample.mp3
Edit Artist
./mp3tag -e -a "Artist Name" sample.mp3
Edit Album
./mp3tag -e -A "Album Name" sample.mp3
Edit Genre
./mp3tag -e -g "Rock" sample.mp3
Edit Comments
./mp3tag -e -c "My Comment" sample.mp3
Data Storage

The project uses the ID3v2.3 metadata section stored inside the MP3 file.

The metadata is organized into individual frames:

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
   +-- Other MP3 Data

Each ID3v2.3 frame contains:

+----------+------------+-------+-------------+
| Frame ID | Frame Size | Flags | Frame Data  |
+----------+------------+-------+-------------+
   4 bytes    4 bytes    2 bytes    Variable

During an edit operation, the application creates a temporary MP3 file, writes the modified metadata, copies the remaining file data, and then replaces the original MP3 file.

Concepts Used

This project demonstrates practical implementation of:

C file handling
Binary file operations
Command-line arguments
String manipulation
Dynamic memory allocation
Pointers
fread() and fwrite()
fseek() and fclose()
Big-endian byte conversion
ID3v2.3 metadata frame processing

Author

Manubolu Dileepchowdary
