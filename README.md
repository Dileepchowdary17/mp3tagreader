# MP3 Tag Editor

A command-line based MP3 metadata editor developed in C for reading and modifying ID3v2.3 metadata stored inside MP3 files. The application supports viewing and editing common metadata such as title, artist, album, year, genre, and comments using C file handling, binary data processing, command-line arguments, string manipulation, dynamic memory allocation, and byte-level metadata processing.

## Features

- **View Metadata** — Display ID3v2.3 metadata stored in an MP3 file
- **Edit Title** — Update the title metadata
- **Edit Artist** — Update the artist metadata
- **Edit Album** — Update the album metadata
- **Edit Year** — Update the release year
- **Edit Genre** — Update the genre metadata
- **Edit Comments** — Update the comments metadata
- **MP3 Validation** — Validate the input file before processing
- **ID3v2.3 Frame Processing** — Identify metadata using standard ID3v2.3 frame identifiers
- **Binary File Handling** — Read and modify MP3 metadata at the byte level
- **Temporary File Processing** — Reconstruct the MP3 using a temporary file during editing
- **Command-Line Interface** — Perform all operations directly from the terminal

## Project Structure

```text
MP3_Tag_Editor/
├── main.c              # Program entry point and command-line handling
├── view.c              # MP3 metadata reading and display operations
├── view.h              # View module function declarations
├── edit.c              # MP3 metadata editing operations
├── edit.h              # Edit module function declarations
├── sample.mp3          # Sample MP3 file used for testing
└── README.md           # Project documentation
```

## Requirements

- GCC or another standard C compiler
- Linux, macOS, or Windows
- Terminal or Command Prompt
- Basic C development environment
- An MP3 file containing ID3v2.3 metadata

No external libraries or third-party dependencies are required.

## File Description

| File | Description |
|---|---|
| `main.c` | Program entry point. Handles command-line arguments, validates operations, and calls the appropriate view or edit function. |
| `view.c` | Implements MP3 metadata reading, ID3 header processing, frame identification, frame-size conversion, and metadata display. |
| `view.h` | Contains function declarations used by the metadata viewing module. |
| `edit.c` | Implements metadata editing by locating the selected ID3v2.3 frame, replacing its data, and reconstructing the MP3 file. |
| `edit.h` | Contains function declarations used by the metadata editing module. |
| `sample.mp3` | Sample MP3 file used for testing metadata viewing and editing operations. |
| `README.md` | Project documentation, usage instructions, implementation details, and examples. |

## Application Flow

### View Metadata

The view operation reads metadata directly from the MP3 file without modifying the original file.

```text
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
Identify Supported Frame IDs
  |
  +----> TIT2 -> Title
  |
  +----> TPE1 -> Artist
  |
  +----> TALB -> Album
  |
  +----> TYER -> Year
  |
  +----> TCON -> Genre
  |
  +----> COMM -> Comments
  |
  v
Display Metadata
  |
  v
Close File
  |
  v
End
```

### Edit Metadata

The edit operation creates a temporary file, copies the original MP3 data while replacing the selected metadata frame, and then replaces the original file.

```text
Start
  |
  v
Read Command-Line Arguments
  |
  v
Check Edit Operation (-e)
  |
  v
Validate Input
  |
  v
Identify Selected Metadata Option
  |
  v
Open Original MP3
  |
  v
Create Temporary MP3
  |
  v
Read ID3 Header and Frames
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
```

## Supported Metadata

The application works with the following ID3v2.3 frame identifiers:

| Option | Frame ID | Metadata |
|---|---|---|
| `-t` | `TIT2` | Title |
| `-a` | `TPE1` | Artist |
| `-A` | `TALB` | Album |
| `-y` | `TYER` | Year |
| `-g` | `TCON` | Genre |
| `-c` | `COMM` | Comments |

The command-line option selects the metadata field, while the corresponding ID3v2.3 frame identifier is used internally to locate that metadata in the MP3 file.

## Compilation

Navigate to the project directory:

```bash
cd MP3_Tag_Editor
```

Compile all source files using GCC:

```bash
gcc main.c view.c edit.c -o mp3tag
```

For compilation with warnings enabled:

```bash
gcc -Wall -Wextra main.c view.c edit.c -o mp3tag
```

After successful compilation, the executable `mp3tag` will be generated.

## Execution

### Linux / macOS

```bash
./mp3tag -v sample.mp3
```

### Windows

```text
mp3tag.exe -v sample.mp3
```

## Usage

The application provides two primary operations:

```text
-v    View MP3 metadata
-e    Edit MP3 metadata
```

### View MP3 Metadata

**Command:**

```bash
./mp3tag -v sample.mp3
```

**Input:**

- `-v` specifies the view operation
- `sample.mp3` specifies the MP3 file to be processed

**Processing:**

1. Validate the MP3 file.
2. Open the file in binary read mode.
3. Read and verify the ID3 header.
4. Read the ID3v2.3 version.
5. Read metadata frames sequentially.
6. Identify supported frame IDs.
7. Extract the corresponding metadata.
8. Display the metadata to the user.

**Example Output:**

```text
ID3 version : 2.3.0
Title       : Baagundu Po
Artist      : Sai Abhyankkar, Sanjith Hegde
Album       : Dude
Year        : 2025
Genre       : Sad
Comments    : Banger
```

The view operation only reads the MP3 file and does not modify its contents.

### Edit MP3 Metadata

The edit operation follows this command format:

```bash
./mp3tag -e <option> "<new value>" sample.mp3
```

Where:

```text
-e          -> Edit operation
<option>    -> Metadata field to modify
<new value> -> New metadata value
sample.mp3  -> Target MP3 file
```

### Edit Title

```bash
./mp3tag -e -t "New Title" sample.mp3
```

The application locates the `TIT2` frame and replaces its existing title with the supplied value.

Example:

```text
Before:
Title : Baagundu Po

Command:
./mp3tag -e -t "New Title" sample.mp3

After:
Title : New Title
```

### Edit Artist

```bash
./mp3tag -e -a "Artist Name" sample.mp3
```

The application locates the `TPE1` frame and updates the artist metadata.

### Edit Album

```bash
./mp3tag -e -A "Album Name" sample.mp3
```

The application locates the `TALB` frame and updates the album metadata.

### Edit Year

```bash
./mp3tag -e -y "2026" sample.mp3
```

The application locates the `TYER` frame and updates the release year.

Example:

```text
Before:
Year : 2025

Command:
./mp3tag -e -y "2026" sample.mp3

After:
Year : 2026
```

### Edit Genre

```bash
./mp3tag -e -g "Rock" sample.mp3
```

The application locates the `TCON` frame and updates the genre metadata.

Example:

```text
Before:
Genre : Sad

Command:
./mp3tag -e -g "Rock" sample.mp3

After:
Genre : Rock
```

### Edit Comments

```bash
./mp3tag -e -c "My Comment" sample.mp3
```

The application locates the `COMM` frame and updates the comment metadata.

Example:

```text
Before:
Comments : Banger

Command:
./mp3tag -e -c "My Comment" sample.mp3

After:
Comments : My Comment
```

## Data Storage

The project does not use a separate database or text file for storing MP3 metadata. Instead, metadata is stored directly inside the ID3v2.3 section of the MP3 file.

The general structure is:

```text
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
```

## ID3v2.3 Frame Structure

Each ID3v2.3 frame contains a frame identifier, frame size, flags, and frame data.

```text
+----------+------------+-------+-------------+
| Frame ID | Frame Size | Flags | Frame Data  |
+----------+------------+-------+-------------+
| 4 bytes  | 4 bytes    | 2 bytes | Variable |
+----------+------------+-------+-------------+
```

For example, a title frame contains:

```text
TIT2
 |
 +-- Frame Size
 |
 +-- Flags
 |
 +-- Encoding
 |
 +-- Title Data
```

The application reads the frame identifier and size, processes the frame data, and maps the identifier to the corresponding metadata field.

## Metadata Editing Procedure

When a metadata field is edited, the application reconstructs the MP3 using a temporary file.

```text
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
    / \
   /   \
 Yes    No
  |      |
  v      v
Replace  Copy Existing
Frame    Frame
  |      |
   \    /
    \  /
     \/
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
```

This approach allows the selected metadata to be updated while preserving the remaining MP3 content.

## Binary File Processing

Since MP3 files contain binary data, the application uses binary file operations for reading and writing.

Important functions used in the project include:

```c
fopen()
fread()
fwrite()
fseek()
fclose()
fgetc()
fputc()
```

These functions are used to:

- Open MP3 files
- Read ID3 headers
- Read metadata frame identifiers
- Read frame sizes
- Read frame data
- Write modified metadata
- Copy remaining MP3 data
- Navigate through the file
- Close files safely

## Big-Endian Frame Size Processing

ID3v2.3 frame sizes are stored across four bytes. The application converts these bytes into an integer before reading the corresponding frame data.

Conceptually:

```text
Byte 0 -> Shift 24 bits
Byte 1 -> Shift 16 bits
Byte 2 -> Shift 8 bits
Byte 3 -> No shift
              |
              v
       Combine the bytes
              |
              v
       Frame Size Integer
```

During editing, the updated frame size is converted back into a four-byte representation before being written to the MP3 file.

## Input Validation

Before processing an MP3 file, the application validates the command-line input.

For example:

```bash
./mp3tag -v sample.mp3
```

The application checks whether the supplied file has the expected `.mp3` extension.

For editing:

```bash
./mp3tag -e -t "New Title" sample.mp3
```

The application validates:

- Operation type
- Metadata option
- New metadata value
- MP3 file name

Invalid input is rejected before the application attempts to modify the file.

## Error Handling

The application provides basic error handling for situations such as:

- Invalid command-line arguments
- Invalid MP3 file extension
- Unable to open the MP3 file
- Missing ID3 tag
- Unable to create the temporary file
- Memory allocation failure
- Unsupported metadata option

Example:

```text
Error: It's not an mp3 file
```

or:

```text
Invalid Input
```

## Testing

The application can be tested using the included `sample.mp3` file.

### View Test

```bash
./mp3tag -v sample.mp3
```

Verify that the expected metadata is displayed.

### Edit Test

For example:

```bash
./mp3tag -e -t "Test Title" sample.mp3
```

After the edit operation, verify the updated metadata:

```bash
./mp3tag -v sample.mp3
```

Expected result:

```text
Title       : Test Title
```

The same procedure can be used to verify artist, album, year, genre, and comments.

## Example Complete Workflow

```text
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
6. Validate the input
       |
       v
7. Locate the corresponding ID3v2.3 frame
       |
       v
8. Create a temporary MP3 file
       |
       v
9. Replace the selected metadata
       |
       v
10. Copy the remaining MP3 data
       |
       v
11. Replace the original MP3
       |
       v
12. View the MP3 again to verify the modification
```

## Concepts Used

This project demonstrates practical implementation of:

- C programming
- Command-line arguments
- File handling
- Binary file I/O
- Pointers
- Character arrays
- String manipulation
- String comparison
- Dynamic memory allocation
- `malloc()` and `free()`
- `fopen()` and `fclose()`
- `fread()` and `fwrite()`
- `fseek()`
- `fgetc()` and `fputc()`
- Bitwise operators
- Byte manipulation
- Big-endian data conversion
- ID3v2.3 metadata frame processing
- Modular programming
- Header files
- Temporary file handling
- Input validation
- Error handling

## Limitations

- The current implementation is designed specifically for ID3v2.3 metadata.
- The application is command-line based.
- MP3 files without compatible ID3 metadata may not provide the expected tags.
- Some metadata frames have specialized structures and may require additional parsing.
- The project is primarily intended to demonstrate C programming, binary file processing, and MP3 metadata manipulation.

## Author

**Dileep**

C Programming | Embedded Systems | VLSI Enthusiast
