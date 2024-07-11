#pragma once

#include "gltfpack.h"

namespace Gltf
{

    public enum class GltfTextureMode
    {
        TextureMode_Raw = TextureMode::TextureMode_Raw,
        TextureMode_ETC1S = TextureMode::TextureMode_ETC1S,
        TextureMode_UASTC = TextureMode::TextureMode_UASTC,
    };

    public ref class GltfSettings
    {
    public:
        Settings* settings;
        //gcroot<Settings*> settings;
    public:
        GltfSettings()
        {
            settings = new Settings();
        }

        ~GltfSettings()
        {
            delete settings;
        }

        static GltfSettings^ defaults();

        property int pos_bits {
            int get() { return settings->pos_bits; }
            void set(int value) { settings->pos_bits = value; }
        }
        property int tex_bits {
            int get() { return settings->tex_bits; }
            void set(int value) { settings->tex_bits = value; }
        }
        property int nrm_bits {
            int get() { return settings->nrm_bits; }
            void set(int value) { settings->nrm_bits = value; }
        }
        property int col_bits {
            int get() { return settings->col_bits; }
            void set(int value) { settings->col_bits = value; }
        }

        property bool pos_normalized {
            bool get() { return settings->pos_normalized; }
            void set(bool value) { settings->pos_normalized = value; }
        }
        property bool pos_float {
            bool get() { return settings->pos_float; }
            void set(bool value) { settings->pos_float = value; }
        }
        property bool tex_float {
            bool get() { return settings->tex_float; }
            void set(bool value) { settings->tex_float = value; }
        }
        property bool nrm_float {
            bool get() { return settings->nrm_float; }
            void set(bool value) { settings->nrm_float = value; }
        }

        property int trn_bits {
            int get() { return settings->trn_bits; }
            void set(int value) { settings->trn_bits = value; }
        }
        property int rot_bits {
            int get() { return settings->rot_bits; }
            void set(int value) { settings->rot_bits = value; }
        }
        property int scl_bits {
            int get() { return settings->scl_bits; }
            void set(int value) { settings->scl_bits = value; }
        }

        property int anim_freq {
            int get() { return settings->anim_freq; }
            void set(int value) { settings->anim_freq = value; }
        }
        property bool anim_const {
            bool get() { return settings->anim_const; }
            void set(bool value) { settings->anim_const = value; }
        }

        property bool keep_nodes {
            bool get() { return settings->keep_nodes; }
            void set(bool value) { settings->keep_nodes = value; }
        }
        property bool keep_materials {
            bool get() { return settings->keep_materials; }
            void set(bool value) { settings->keep_materials = value; }
        }
        property bool keep_extras {
            bool get() { return settings->keep_extras; }
            void set(bool value) { settings->keep_extras = value; }
        }

        property bool mesh_merge {
            bool get() { return settings->mesh_merge; }
            void set(bool value) { settings->mesh_merge = value; }
        }
        property bool mesh_instancing {
            bool get() { return settings->mesh_instancing; }
            void set(bool value) { settings->mesh_instancing = value; }
        }

        property float simplify_threshold {
            float get() { return settings->simplify_threshold; }
            void set(float value) { settings->simplify_threshold = value; }
        }
        property bool simplify_aggressive {
            bool get() { return settings->simplify_aggressive; }
            void set(bool value) { settings->simplify_aggressive = value; }
        }
        property bool simplify_lock_borders {
            bool get() { return settings->simplify_lock_borders; }
            void set(bool value) { settings->simplify_lock_borders = value; }
        }
        property float simplify_debug {
            float get() { return settings->simplify_debug; }
            void set(float value) { settings->simplify_debug = value; }
        }

        property int meshlet_debug {
            int get() { return settings->meshlet_debug; }
            void set(int value) { settings->meshlet_debug = value; }
        }

        property bool texture_ktx2 {
            bool get() { return settings->texture_ktx2; }
            void set(bool value) { settings->texture_ktx2 = value; }
        }
        property bool texture_embed {
            bool get() { return settings->texture_embed; }
            void set(bool value) { settings->texture_embed = value; }
        }
        property bool texture_ref {
            bool get() { return settings->texture_ref; }
            void set(bool value) { settings->texture_ref = value; }
        }

        property bool texture_pow2 {
            bool get() { return settings->texture_pow2; }
            void set(bool value) { settings->texture_pow2 = value; }
        }
        property bool texture_flipy {
            bool get() { return settings->texture_flipy; }
            void set(bool value) { settings->texture_flipy = value; }
        }
        property float texture_scale {
            float get() { return settings->texture_scale; }
            void set(float value) { settings->texture_scale = value; }
        }
        property int texture_limit {
            int get() { return settings->texture_limit; }
            void set(int value) { settings->texture_limit = value; }
        }

        property GltfTextureMode texture_mode[int]{
            GltfTextureMode get(int index) {
                return static_cast<GltfTextureMode>(settings->texture_mode[index]);
            }
            void set(int index, GltfTextureMode value) {
                settings->texture_mode[index] = static_cast<TextureMode>(value);
            }
        };

        property int texture_quality[int]
        {
            int get(int index) {
                return settings->texture_quality[index];
            }
            void set(int index, int value) {
                settings->texture_quality[index] = value;
            }
        }

            property int texture_jobs
        {
            int get() { return settings->texture_jobs; }
            void set(int value) { settings->texture_jobs = value; }
        }

        property bool quantize
        {
            bool get() { return settings->quantize; }
            void set(bool value) { settings->quantize = value; }
        }

        property bool compress
        {
            bool get() { return settings->compress; }
            void set(bool value) { settings->compress = value; }
        }
        property bool compressmore
        {
            bool get() { return settings->compressmore; }
            void set(bool value) { settings->compressmore = value; }
        }
        property bool fallback
        {
            bool get() { return settings->fallback; }
            void set(bool value) { settings->fallback = value; }
        }

        property int verbose
        {
            int get() { return settings->verbose; }
            void set(int value) { settings->verbose = value; }
        }
    };

    public ref class GltfPack
    {

    public:
        static void commandline(array<System::String^>^ args);
        static int gltfpack(System::String^ input, System::String^ output, System::String^ report, const GltfSettings^ settings);
    };

}