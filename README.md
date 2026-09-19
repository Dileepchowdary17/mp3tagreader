MP3 Tag Reader

A command-line based MP3 Tag Editor developed in C for reading and modifying ID3v2.3 metadata stored inside MP3 files. The project demonstrates practical usage of C programming, file handling, structures, strings, dynamic memory allocation, and binary data processing.

Features
View MP3 metadata from ID3v2.3 tags.
Edit individual MP3 tags from the command line.
Supports the following metadata:
Title (TIT2)
Artist (TPE1)
Album (TALB)
Year (TYER)
Genre (TCON)
Comments (COMM)
Validates MP3 file extension before processing.
Reads and writes MP3 files using binary file operations.
Handles ID3 frame sizes using big-endian conversion.
Uses a temporary file during metadata modification to preserve the remaining MP3 data.
Provides command-line based interaction without requiring a graphical interface.
Project Structure
MP3_Tag_Editor/
│
├── main.c
├── view.c
├── view.h
├── edit.c
├── edit.h
├── sample.mp3
└── README.md
Requirements
Operating System: Linux / Windows with GCC or MinGW
Compiler: GCC
Language: C
MP3 File: ID3v2.3 compatible MP3 file
Basic command-line/terminal environment

No external libraries are required.

File Description
File	Description
main.c	Handles command-line arguments and determines whether the user wants to view or edit metadata.
view.c	Contains the logic for reading and displaying ID3v2.3 metadata from an MP3 file.
view.h	Contains function declarations required by view.c.
edit.c	Contains the logic for locating and modifying MP3 metadata frames.
edit.h	Contains function declarations required by edit.c.
sample.mp3	Sample MP3 file used for testing the application.
README.md	Project documentation.
Application Flow
View Metadata
User Command
     │
     ▼
   main.c
     │
     ▼
Validate MP3 File
     │
     ▼
  view.c
     │
     ▼
Open MP3 in Binary Mode
     │
     ▼
Read ID3 Header
     │
     ▼
Read Frame ID + Frame Size
     │
     ▼
Extract Frame Data
     │
     ▼
Display Metadata
Edit Metadata
User Command
     │
     ▼
   main.c
     │
     ▼
Validate Arguments
     │
     ▼
  edit.c
     │
     ▼
Open Original MP3
     │
     ▼
Create Temporary MP3
     │
     ▼
Read ID3 Frames
     │
     ▼
Find Required Frame
     │
     ▼
Replace Metadata
     │
     ▼
Copy Remaining MP3 Data
     │
     ▼
Replace Original File
Compilation

Clone the repository and navigate to the project directory:

cd MP3_Tag_Editor

Compile the project using GCC:

gcc -Wall -Wextra main.c view.c edit.c -o mp3tag

This generates the executable:

mp3tag
Execution
View MP3 Metadata
./mp3tag -v sample.mp3

Example output:

ID3 version : 2.3.0
Title       : Baagundu Po
Artist      : Sai Abhyankkar, Sanjith Hegde
Album       : Dude
Year        : 2025
Genre       : Pop
Comments    : Sample comment
Usage
View Metadata
./mp3tag -v sample.mp3
Edit Title
./mp3tag -e -t "New Title" sample.mp3
Edit Year
./mp3tag -e -y "2026" sample.mp3
Edit Artist
./mp3tag -e -a "Artist Name" sample.mp3
Edit Album
./mp3tag -e -A "Album Name" sample.mp3
Edit Genre
./mp3tag -e -g "Pop" sample.mp3
Edit Comments
./mp3tag -e -c "My Comment" sample.mp3
Supported ID3v2.3 Frames
Option	Frame ID	Metadata
-t	TIT2	Title
-a	TPE1	Artist
-A	TALB	Album
-y	TYER	Year
-g	TCON	Genre
-c	COMM	Comments
Data Storage

The project works directly with the ID3v2.3 metadata stored inside the MP3 file.

An ID3v2.3 tag consists of a header followed by multiple metadata frames:

MP3 File
│
├── ID3 Header
│
├── TIT2 → Title
├── TPE1 → Artist
├── TALB → Album
├── TYER → Year
├── TCON → Genre
├── COMM → Comments
└── Other Frames

Each frame contains information such as:

Frame ID
   ↓
Frame Size
   ↓
Flags
   ↓
Frame Data

The application reads these fields using C file-handling functions such as fopen(), fread(), fwrite(), fseek(), and fclose().

When editing a tag, the application creates a temporary MP3 file, writes the updated metadata, copies the remaining data, and then replaces the original file.

Technologies Used
C Programming
File Handling
Binary File Processing
String Manipulation
Dynamic Memory Allocation
Command-Line Arguments
ID3v2.3 Metadata
GCC Compiler


Author

Manubolu Dileep chowdary
