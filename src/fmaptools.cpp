//© Copyright 2014-2022, Juan Linietsky, Ariel Manzur and the Godot community (CC-BY 3.0)
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/label.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

#include "fmaptools.h"

using namespace godot;

void Fmaptools::_bind_methods()
{
    // ClassDB::bind_method(D_METHOD("circular_sum_noise", "&rng", "height_array"), &Fmaptools::circular_sum_noise);
    ClassDB::bind_static_method( "Fmaptools", D_METHOD("circular_sum_noise", "&rng", "height_array"), &Fmaptools::circular_sum_noise);
}

Fmaptools::Fmaptools()
{
    // initialize any variables here
    count = 0;
}

Fmaptools::~Fmaptools()
{
    // add your cleanup here
}

PackedFloat32Array Fmaptools::circular_sum_noise(Ref<RandomNumberGenerator> rng, PackedFloat32Array height_array)
{
    int i_height = 600;
    int i_width = 1200;
    int RAD_MAX = 64;
    int RAD_MIN = 8;
    int SPACING = 4;

    // Precompute a lookup table for circle coordinates
    godot::Array circle_lookup_table;
    circle_lookup_table.resize(RAD_MAX + 1);
    for (int r = RAD_MIN; r <= RAD_MAX; ++r) {
        godot::Array circle_pixels;
        for (int y = -r; y <= r; ++y) {
            for (int x = -r; x <= r; ++x) {
                if (x*x + y*y <= r*r) {
                    circle_pixels.push_back(Vector2i(x, y));
                }
            }
        }
        circle_lookup_table[r] = circle_pixels;
    }

    // Iterate over the pixels in the lookup table
    for (int yy = RAD_MAX; yy < i_height - RAD_MAX; yy += SPACING) {
        for (int xx = RAD_MAX; xx < i_width - RAD_MAX; xx += SPACING) {
            Vector2i center(xx, yy);
            int val = rng->randi() % 255; // random unsigned integer between 0 and 254
            int circle_rad = (int)UtilityFunctions::ceil(rng->randi_range(RAD_MIN, RAD_MAX));
            const godot::Array circle_pixels = circle_lookup_table[circle_rad];
            for (int i = 0; i < circle_pixels.size(); ++i) {
                Vector2i offset = circle_pixels[i];
                Vector2i coord = center + offset;
                height_array[coord.x + coord.y * i_width] += val;
            }
        }
    }

    return height_array;
}