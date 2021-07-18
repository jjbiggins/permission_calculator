+=======================================================================================================================================+
|Value	|                               Meaning                                                                                         |
+=======================================================================================================================================+
|777	|    (rwxrwxrwx)    No restrictions on permissions. Anybody may do anything.                                                    |
|       |                   Generally not a desirable setting.                                                                          |
|-------|-------------------------------------------------------------------------------------------------------------------------------|
|755	|    (rwxr-xr-x)    The file's owner may read, write, and execute the file.                                                     |
|       |                   All others may read and execute the file. This setting is common for programs that are used by all users.   |
|-------|-------------------------------------------------------------------------------------------------------------------------------+
|700	|   (rwx------)     The file's owner may read, write, and execute the file. Nobody else has any rights.                         | 
|       |                   This setting is useful for programs that only the owner may use and must be kept private from others.       |
|-------|-------------------------------------------------------------------------------------------------------------------------------+
|666	|   (rw-rw-rw-)     All users may read and write the file.                                                                      |
|-------|-------------------------------------------------------------------------------------------------------------------------------+
|644	|   (rw-r--r--)     The owner may read and write a file, while all others may only read the file.                               |
|       |                   A common setting for data files that everybody may read, but only the owner may change.                     |
|-------|-------------------------------------------------------------------------------------------------------------------------------+
|600	|   (rw-------)     The owner may read and write a file. All others have no rights.                                             |
|       |                    A common setting for data files that the owner wants to keep private.                                      |
----------------------------------------------------------------------------------------------------------------------------------------+
