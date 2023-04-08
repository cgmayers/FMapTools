//© Copyright 2014-2022, Juan Linietsky, Ariel Manzur and the Godot community (CC-BY 3.0)
#ifndef FMAPTOOLS_CLASS_H
#define FMAPTOOLS_CLASS_H

// We don't need windows.h in this plugin but many others do and it throws up on itself all the time
// So best to include it and make sure CI warns us when we use something Microsoft took for their own goals....
#ifdef WIN32
#include <windows.h>
#endif

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/classes/random_number_generator.hpp>
#include <godot_cpp/classes/geometry2d.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/array.hpp>
#include <godot_cpp/variant/typed_array.hpp>
#include <godot_cpp/variant/packed_float32_array.hpp>
#include <godot_cpp/core/math.hpp>

#include <godot_cpp/classes/control.hpp>
#include <godot_cpp/classes/global_constants.hpp>
#include <godot_cpp/classes/viewport.hpp>
#include <godot_cpp/core/binder_common.hpp>

// #include <godot-cpp/gdextension
// #include <godot-cpp/include
// #include <godot-cpp/gen/include


using namespace godot;

class Fmaptools : public RefCounted
{
    GDCLASS(Fmaptools, RefCounted);

    PackedFloat32Array height_array;
    int count;

private:
    static int variable_name;

protected:
    static void _bind_methods();

public:
    Fmaptools();
    ~Fmaptools();

    static PackedFloat32Array circular_sum_noise(Ref<RandomNumberGenerator> rng, PackedFloat32Array height_array);
};

#endif // FMAPTOOLS_CLASS_H