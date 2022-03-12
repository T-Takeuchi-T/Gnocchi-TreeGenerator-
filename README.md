# Gnocchi -TreeGenerator-
Gnocchi -TreeGenerator- is software for generating trees.

## DEMO
### _How to use Gnocci(β)_
![How to use Gnocci(β)](https://user-images.githubusercontent.com/93573362/158017098-645e2b76-dd1a-4926-b184-ea915a2af25c.png)
### Ⓐ Old window
#### ① Character string input
#### ② Number of fractal repetitions
#### ③ f Character string input after change
#### ④ Initial position
#### ⑤ Depth limit in pseudo 3D
#### ⑥ Rotation of product (°)
#### ⑦ Pen travel distance, rotation amount, magnification of vertex generation radius (%)
#### ⑧ Change generation style
0) Win32 API Line drawing (pseudo 3D)
1) Drawing on Win32 API surface (pseudo 3D)
2) .net framework drawing with lines (pseudo 3D)
3) Drawing on .net framework surface (pseudo 3D)
4) Drawing with OpenGL lines (pseudo 3D)
5) Drawing on OpenGL surface (pseudo 3D)
6) Drawing with OpenGL lines
7) Drawing on the OpenGL surface
8) (unused)
9) Drawing with OpenGL texture
#### ⑨ Expansion / reduction ratio for each layer (%)
#### ⑩ Output fbxout.fbx to the same location as the executable file
#### ⑪ Get one mesh from fbxin.fbx in the same location as the executable file
#### ⑫ Manual input enable / disable switching
0) Ⓐ ① ③ input is invalidated, only accepted from new window
1) Accept from both old and new
#### * Output to the background when Ⓐ⑧ is 1), 2)
### Ⓑ New window
#### ①Output when ①Ⓐ⑧ is other than 1) and 2)
* Left-click, wheel-click : Parallel movement of viewpoint
* Mouse wheel: Viewpoint forward / backward
* Move while right-clicking: Rotate viewpoint
#### ② Node tree
* Click the node to select
* Right-click a node to display the node menu.
#### ③ Properties of the selected node
![Properties of the selected node](https://user-images.githubusercontent.com/93573362/158017105-6a48dc4e-a425-49a0-b830-de24e494f68c.png)
#### ④ Node distribution and fractals
![Fractals](https://user-images.githubusercontent.com/93573362/158017122-4bfc6de6-0e9d-4aba-89f7-a0ad7d5f40a3.png)
![Node distribution](https://user-images.githubusercontent.com/93573362/158017125-bba73149-1571-4620-bb36-29db15a7f506.png)
### _Demo videos_
#### _New window usage example_

#### _Old window usage example_

#### _Property "type" and input in new window_

#### _Property "type" and input in old window_

## Requirements
Gnocchi -TreeGenerator- requires the following to run:
* OpenGL
* FBX SDK
* .Net Framework

## Author
* Mint0108
* ywwwwwww

## License
