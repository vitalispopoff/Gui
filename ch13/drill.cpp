//#include "../_add_libs/PPP2Code/Simple_window.h"
#include "ch13.h"

namespace ch13
{
	namespace drill
	{

		namespace d01
		{
			void main()
			{
				int
					displayX	{x_max ()},
					displayY	{y_max ()},
					windowX		{800},
					windowY		{1000},
					anchorX		{(displayX - windowX) >> 1},
					anchorY		{(displayY - windowY) >> 1};
				Simple_window
					window		{Point {anchorX, anchorY}, windowX, windowY, "drill 01"};
				window.wait_for_button();
			}
		}

		namespace d02
		{
			void main()
			{				
				int
					displayX	{x_max ()},
					displayY	{y_max ()},
					windowX		{800},
					windowY		{1000},
					anchorX		{(displayX - windowX) >> 1},
					anchorY		{(displayY - windowY) >> 1};
				Simple_window
					window		{Point {anchorX, anchorY}, windowX, windowY, "drill 02"};
				Vector_ref<Line>
					lines;
				int
					size		{800},
					grid		{8},
					scale		{size / grid};					
				for (int i = 0; i <= size; i += scale)
				{
					lines.push_back	(new Line {Point {i, 0}, Point {i, size}});
					window.attach (lines [lines.size() - 1]);
					lines.push_back (new Line {Point {0, i}, Point {size, i}});
					window.attach (lines [lines.size() - 1]);
				};
				window.wait_for_button();
			}
		}

		namespace d03
		{
			void main()
			{
				int
					displayX	{x_max ()},
					displayY	{y_max ()},
					windowX		{800},
					windowY		{1000},
					anchorX		{(displayX - windowX) >> 1},
					anchorY		{(displayY - windowY) >> 1};
				Simple_window
					window		{Point {anchorX, anchorY}, windowX, windowY, "drill 02"};
				Vector_ref<Line>
					lines;
				Vector_ref<Graph_lib::Rectangle>
					rectangles;
				int
					size		{800},
					grid		{8},
					scale		{size / grid};		
				for (int i = 0; i <= size; i += scale)
				{
					lines.push_back	(new Line {Point {i, 0}, Point {i, size}});
					window.attach (lines [lines.size() - 1]);
					lines.push_back (new Line {Point {0, i}, Point {size, i}});
					window.attach (lines [lines.size() - 1]);
				};
				Color
					rect_color {Color::Color_type::red};
				Line_style
					rect_style {Line_style::Line_style_type::solid, 2};
				for (int i = 0; i < size; i += scale)
				{	
					rectangles.push_back (
						new Graph_lib::Rectangle {
						Point {i + 1, i + 1},					/// moved the rects by 1 to fit inside the grid
						scale - 1, scale - 1}
					);
					int
						index {rectangles.size() - 1};
					rectangles[index].set_color (rect_color);
					//rectangles[index].set_style (rect_style);
					window.attach (rectangles [index]);
				}
				window.wait_for_button();
			}
		}

		namespace d04
		{
			void main()
			{
				int
					displayX	{x_max ()},
					displayY	{y_max ()},
					windowX		{800},
					windowY		{1000},
					anchorX		{(displayX - windowX) >> 1},
					anchorY		{(displayY - windowY) >> 1};
				Simple_window
					window		{Point {anchorX, anchorY}, windowX, windowY, "drill 02"};
				//------------------------------
				Vector_ref<Line>
					lines;
				int
					size		{800},
					grid		{8},
					scale		{size / grid};		
				for (int i = 0; i <= size; i += scale)
				{
					lines.push_back	(new Line {Point {i, 0}, Point {i, size}});
					window.attach (lines [lines.size() - 1]);
					lines.push_back (new Line {Point {0, i}, Point {size, i}});
					window.attach (lines [lines.size() - 1]);
				};
				//------------------------------
				Vector_ref<Graph_lib::Image>
					images;
				string
					filename	{"E:\\_LAB\\_C\\Gui\\_other\\kuvaton-kuka_jatti_ikkunan_auki2.jpg"};	/// 640x427
				int
					dimensions {200},
					copies {3},
					margins {(size - (dimensions  * copies)) >> 1},
					mask_anchors [] 
					{
						2 * 210,								/// top right X
						15,										/// top right Y
						210,									/// middle X
						100 + 15,								/// middle Y
						0,										/// bottom left X
						200 + 15								/// bottom left Y
					};					
				for (int i = 0 ; i < copies; ++i)
				{
					int
						anchorX	{size - margins - (i + 1) * dimensions},
						anchorY	{margins + i * dimensions};
					images.push_back (
						new Image { 
							Point { anchorX, anchorY}, 
							filename, 
							Suffix::Encoding::jpg				/// shouldn't hardcode this one
						}
					);
					int
						index {images.size() - 1};
					images[index].set_mask (
						Point {
							mask_anchors[i * 2], 
							mask_anchors[(i * 2) + 1]},
						dimensions,
						dimensions
					);
					window.attach (images[index]);
				}
				//------------------------------
				Vector_ref<Graph_lib::Rectangle>
					rectangles;
				Color
					rect_color {Color::Color_type::red};
				Line_style
					rect_style {Line_style::Line_style_type::solid, 2};
				for (int i = 0; i < size; i += scale)
				{	
					rectangles.push_back (
						new Graph_lib::Rectangle {
						Point {i + 1, i + 1},					/// moved the rects by 1 to fit inside the grid
						scale - 1, scale - 1}
					);
					int
						index {rectangles.size() - 1};
					rectangles[index].set_color (rect_color);
					window.attach (rectangles [index]);
				}		
				window.wait_for_button();
			}
		}

		namespace d05
		{
			void main()
			{
				int
					displayX	{x_max ()},
					displayY	{y_max ()},
					windowX		{800},
					windowY		{1000},
					anchorX		{(displayX - windowX) >> 1},
					anchorY		{(displayY - windowY) >> 1};
				Simple_window
					window		{Point {anchorX, anchorY}, windowX, windowY, "drill 02"};
				//------------------------------
				Vector_ref<Line>
					lines;
				int
					size		{800},
					grid		{8},
					scale		{size / grid};		
				for (int i = 0; i <= size; i += scale)
				{
					lines.push_back	(new Line {Point {i, 0}, Point {i, size}});
					window.attach (lines [lines.size() - 1]);
					lines.push_back (new Line {Point {0, i}, Point {size, i}});
					window.attach (lines [lines.size() - 1]);
				};
				//------------------------------
				Vector_ref<Graph_lib::Image>
					images;
				string
					filename	{"E:\\_LAB\\_C\\Gui\\_other\\kuvaton-kuka_jatti_ikkunan_auki2.jpg"};	/// 640x427
				int
					dimensions {200},
					copies {3},
					margins {(size - (dimensions  * copies)) >> 1},
					mask_anchors [] 
					{
						2 * 210,								/// top right X
						15,										/// top right Y
						210,									/// middle X
						100 + 15,								/// middle Y
						0,										/// bottom left X
						200 + 15								/// bottom left Y
					};					
				for (int i = 0 ; i < copies; ++i)
				{
					int
						anchorX	{size - margins - (i + 1) * dimensions},
						anchorY	{margins + i * dimensions};
					images.push_back (
						new Image { 
							Point { anchorX, anchorY}, 
							filename, 
							Suffix::Encoding::jpg				/// shouldn't hardcode this one
						}
					);
					int
						index {images.size() - 1};
					images[index].set_mask (
						Point {
							mask_anchors[i * 2], 
							mask_anchors[(i * 2) + 1]},
						dimensions,
						dimensions
					);
					window.attach (images[index]);
				}
				//------------------------------
				Vector_ref<Graph_lib::Rectangle>
					rectangles;
				Color
					rect_color {Color::Color_type::red};
				Line_style
					rect_style {Line_style::Line_style_type::solid, 2};
				for (int i = 0; i < size; i += scale)
				{	
					rectangles.push_back (
						new Graph_lib::Rectangle {
						Point {i + 1, i + 1},					/// moved the rects by 1 to fit inside the grid
						scale - 1, scale - 1}
					);
					int
						index {rectangles.size() - 1};
					rectangles[index].set_color (rect_color);
					window.attach (rectangles [index]);
				}
				images.push_back (
					new Image {
						Point {0, 0},
						filename,
						Suffix::Encoding::jpg
					});
																/// since the shape doesn't return its position, and move() adds to the coordinates
																/// we have to remember the current position of the mobile_image
																///	and adjust the numbers accordingly to keep the mobile_image in the grid
				int
					mobile_image_size	{100},
					mobile_image_index	{images.size() - 1},
					mobile_image_x		{0},
					mobile_image_y		{0};
				images[mobile_image_index].set_mask (
					Point {60, 15},								/// again - arbitrarily chosen variables
					mobile_image_size,
					mobile_image_size
				);
				window.attach(images[images.size() - 1]);
				while (true)
				{
					int
						move_x	{((rand() % grid) * scale) - mobile_image_x},
						move_y	{((rand() % grid) * scale) - mobile_image_y};
						mobile_image_x += move_x;
						mobile_image_y += move_y;
					images[mobile_image_index].move (move_x, move_y);
					window.wait_for_button();
				};
			}
		}
	}
}