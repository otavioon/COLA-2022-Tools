#define NULL ((void*)0)
typedef unsigned long size_t;  // Customize by platform.
typedef long intptr_t; typedef unsigned long uintptr_t;
typedef long scalar_t__;  // Either arithmetic or pointer type.
/* By default, we understand bool (as a convenience). */
typedef int bool;
#define false 0
#define true 1

/* Forward declarations */
typedef  struct TYPE_34__   TYPE_9__ ;
typedef  struct TYPE_33__   TYPE_8__ ;
typedef  struct TYPE_32__   TYPE_7__ ;
typedef  struct TYPE_31__   TYPE_6__ ;
typedef  struct TYPE_30__   TYPE_5__ ;
typedef  struct TYPE_29__   TYPE_4__ ;
typedef  struct TYPE_28__   TYPE_3__ ;
typedef  struct TYPE_27__   TYPE_2__ ;
typedef  struct TYPE_26__   TYPE_1__ ;
typedef  struct TYPE_25__   TYPE_15__ ;
typedef  struct TYPE_24__   TYPE_14__ ;
typedef  struct TYPE_23__   TYPE_13__ ;
typedef  struct TYPE_22__   TYPE_12__ ;
typedef  struct TYPE_21__   TYPE_11__ ;
typedef  struct TYPE_20__   TYPE_10__ ;

/* Type definitions */
struct TYPE_21__ {unsigned int width; unsigned int height; scalar_t__ userdata; } ;
typedef  TYPE_11__ video_frame_info_t ;
struct font_glyph {float draw_offset_x; float draw_offset_y; float width; float height; float atlas_offset_x; float atlas_offset_y; float advance_x; float advance_y; } ;
struct TYPE_29__ {int /*<<< orphan*/  ps; } ;
struct TYPE_28__ {int /*<<< orphan*/  ps; } ;
struct TYPE_30__ {unsigned int offset; TYPE_4__ shader; TYPE_3__ shader_font; int /*<<< orphan*/  vbo; scalar_t__ capacity; int /*<<< orphan*/  enabled; } ;
struct TYPE_33__ {scalar_t__ Height; scalar_t__ Width; } ;
struct TYPE_22__ {TYPE_5__ sprites; int /*<<< orphan*/  device; int /*<<< orphan*/  blend_enable; TYPE_8__ viewport; } ;
typedef  TYPE_12__ d3d10_video_t ;
struct TYPE_26__ {int scaling; scalar_t__ rotation; } ;
struct TYPE_34__ {float u; float v; float w; float h; } ;
struct TYPE_32__ {int x; int y; float w; float h; } ;
struct TYPE_23__ {unsigned int* colors; TYPE_1__ params; TYPE_9__ coords; TYPE_7__ pos; } ;
typedef  TYPE_13__ d3d10_sprite_t ;
struct TYPE_20__ {scalar_t__ Height; scalar_t__ Width; } ;
struct TYPE_25__ {TYPE_10__ desc; } ;
struct TYPE_24__ {TYPE_15__ texture; TYPE_2__* atlas; int /*<<< orphan*/  font_data; TYPE_6__* font_driver; } ;
typedef  TYPE_14__ d3d10_font_t ;
struct TYPE_31__ {struct font_glyph* (* get_glyph ) (int /*<<< orphan*/ ,char) ;} ;
struct TYPE_27__ {int dirty; int /*<<< orphan*/  buffer; int /*<<< orphan*/  width; int /*<<< orphan*/  height; } ;

/* Variables and functions */
 int /*<<< orphan*/  D3D10Draw (int /*<<< orphan*/ ,unsigned int,int) ; 
 int /*<<< orphan*/  D3D10MapBuffer (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,void**) ; 
 int /*<<< orphan*/  D3D10SetBlendState (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ *,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  D3D10SetPShader (int /*<<< orphan*/ ,int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  D3D10UnmapBuffer (int /*<<< orphan*/ ) ; 
 int /*<<< orphan*/  D3D10_DEFAULT_SAMPLE_MASK ; 
 int /*<<< orphan*/  D3D10_MAP_WRITE_NO_OVERWRITE ; 
 int /*<<< orphan*/  DXGI_FORMAT_A8_UNORM ; 
#define  TEXT_ALIGN_CENTER 129 
#define  TEXT_ALIGN_RIGHT 128 
 int d3d10_font_get_message_width (TYPE_14__*,char const*,unsigned int,float) ; 
 int /*<<< orphan*/  d3d10_set_texture_and_sampler (int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_15__*) ; 
 int /*<<< orphan*/  d3d10_update_texture (int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,int /*<<< orphan*/ ,TYPE_15__*) ; 
 int roundf (double) ; 
 struct font_glyph* stub1 (int /*<<< orphan*/ ,unsigned int) ; 
 struct font_glyph* stub2 (int /*<<< orphan*/ ,char) ; 
 unsigned int utf8_walk (char const**) ; 

__attribute__((used)) static void d3d10_font_render_line(
      video_frame_info_t* video_info,
      d3d10_font_t*       font,
      const char*         msg,
      unsigned            msg_len,
      float               scale,
      const unsigned int  color,
      float               pos_x,
      float               pos_y,
      unsigned            text_align)
{
   unsigned                 i, count;
   void*                    mapped_vbo;
   d3d10_sprite_t*          v;
   d3d10_video_t*           d3d10  = (d3d10_video_t*)video_info->userdata;
   unsigned                 width  = video_info->width;
   unsigned                 height = video_info->height;
   int                      x      = roundf(pos_x * width);
   int                      y      = roundf((1.0 - pos_y) * height);

   if (  !d3d10                  ||
         !d3d10->sprites.enabled ||
         msg_len > (unsigned)d3d10->sprites.capacity)
      return;

   if (d3d10->sprites.offset + msg_len > (unsigned)d3d10->sprites.capacity)
      d3d10->sprites.offset = 0;

   switch (text_align)
   {
      case TEXT_ALIGN_RIGHT:
         x -= d3d10_font_get_message_width(font, msg, msg_len, scale);
         break;

      case TEXT_ALIGN_CENTER:
         x -= d3d10_font_get_message_width(font, msg, msg_len, scale) / 2;
         break;
   }

   D3D10MapBuffer(d3d10->sprites.vbo, D3D10_MAP_WRITE_NO_OVERWRITE, 0, (void**)&mapped_vbo);
   v = (d3d10_sprite_t*)mapped_vbo + d3d10->sprites.offset;

   for (i = 0; i < msg_len; i++)
   {
      const struct font_glyph* glyph;
      const char*              msg_tmp = &msg[i];
      unsigned                 code    = utf8_walk(&msg_tmp);
      unsigned                 skip    = msg_tmp - &msg[i];

      if (skip > 1)
         i += skip - 1;

      glyph = font->font_driver->get_glyph(font->font_data, code);

      if (!glyph) /* Do something smarter here ... */
         glyph = font->font_driver->get_glyph(font->font_data, '?');

      if (!glyph)
         continue;

      v->pos.x = (x + (glyph->draw_offset_x * scale)) / (float)d3d10->viewport.Width;
      v->pos.y = (y + (glyph->draw_offset_y * scale)) / (float)d3d10->viewport.Height;
      v->pos.w = glyph->width * scale / (float)d3d10->viewport.Width;
      v->pos.h = glyph->height * scale / (float)d3d10->viewport.Height;

      v->coords.u = glyph->atlas_offset_x / (float)font->texture.desc.Width;
      v->coords.v = glyph->atlas_offset_y / (float)font->texture.desc.Height;
      v->coords.w = glyph->width / (float)font->texture.desc.Width;
      v->coords.h = glyph->height / (float)font->texture.desc.Height;

      v->params.scaling  = 1;
      v->params.rotation = 0;

      v->colors[0] = color;
      v->colors[1] = color;
      v->colors[2] = color;
      v->colors[3] = color;

      v++;

      x += glyph->advance_x * scale;
      y += glyph->advance_y * scale;
   }

   count = v - ((d3d10_sprite_t*)mapped_vbo + d3d10->sprites.offset);
   D3D10UnmapBuffer(d3d10->sprites.vbo);

   if (!count)
      return;

   if (font->atlas->dirty)
   {
      d3d10_update_texture(
            d3d10->device,
            font->atlas->width, font->atlas->height, font->atlas->width,
            DXGI_FORMAT_A8_UNORM, font->atlas->buffer, &font->texture);
      font->atlas->dirty = false;
   }

   d3d10_set_texture_and_sampler(d3d10->device, 0, &font->texture);
   D3D10SetBlendState(d3d10->device, d3d10->blend_enable, NULL, D3D10_DEFAULT_SAMPLE_MASK);

   D3D10SetPShader(d3d10->device, d3d10->sprites.shader_font.ps);
   D3D10Draw(d3d10->device, count, d3d10->sprites.offset);
   D3D10SetPShader(d3d10->device, d3d10->sprites.shader.ps);

   d3d10->sprites.offset += count;
}