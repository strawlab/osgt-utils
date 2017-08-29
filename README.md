# osgt-utils

Programs to operate on [OpenSceneGraph](http://openscenegraph.org) .osgt files.

## Building

On Ubuntu:

    sudo apt-get install cmake libopenscenegraph-dev
    mkdir build
    cmake ..
    make

## Usage

### osgtsplit

`osgtsplit` splits one .osgt file into multiple components.

Example usage:

    ./osgtsplit source.osgt

Example result:

    num children: 2
      saving child "Cube" to "source.osgt.part-0.osgt"
      saving child "Cylinder" to "source.osgt.part-1.osgt"

### osgtmerge

`osgtmerge` joins two source .osgt files into a new .osgt file.

Example usage:

    ./osgtmerge source1.osgt source2.osgt dest.osgt

Example result:

    appending 1 children from "source2.osgt" into data from "source1.osgt"
    saved to dest.osgt
