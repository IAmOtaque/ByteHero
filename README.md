# ByteHero Jack

This simple program can add null bytes (00) to any file you specify. You can use it for adding bytes to .dll files (Assembly-CSharp.dll) if games have protection that checks the file size, if you need to replace an image with the image with same size etc.

# Version

- Jack (0.0.1). 1st and last.

# Compile

You can compile this code using mingw (<code>g++ src/main.cpp -o build/ByteHero.exe</code> (Win) or <code>g++ src/main.cpp -o build/bytehero && chmod +x build/bytehero && ./build/bytehero</code> (Linux))
