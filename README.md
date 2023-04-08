# FMapTools
FMapTools (Fantasy Map Tools) is meant to serve as a continually expanding C++ GDExtension for Godot 4 that helps me facilitate the handling of large amounts of data (e.g. large heightmap arrays, tens of thousands of NPCs in JSON format, etc) needed for a large-scale fantasy world map generator and simulator. I intend to add C++ functions here when they are too taxing for GDScript.

Since I'm very early in the process of porting over code from Game Maker Studio 2 to Godot 4, there is not much here yet.

Circular Sum Noise
Based on the 2017 method described by RujiK in the Game Maker Community (https://forum.gamemaker.io/index.php?threads/pure-gml-perlin-noise-function.25534/). Takes a heightmap as a PackedFloat32Array, and adds Circular Sum Noise with 4-pixel spacing, minimum radii of 8, and maximum radii of 64.
