#include <osgDB/ReadFile>
#include <osgDB/WriteFile>
#include <osgDB/FileUtils>
#include "util.hpp"

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " source1 source2 dest" << std::endl;
        return 1;
    }

    std::string source1 = argv[1];
    osg::Node* node_source1 = osgDB::readNodeFile(source1);
    if (node_source1==NULL) {
        std::cerr << "source1 file not loaded \"" << source1 << "\"" << std::endl;
        return 1;
    }

    std::string source2 = argv[2];
    osg::Node* node_source2 = osgDB::readNodeFile(source2);
    if (node_source2==NULL) {
        std::cerr << "source2 file not loaded \"" << source2 << "\"" << std::endl;
        return 1;
    }

    std::string dest_filename = argv[3];

    osg::Group* group_source1 = node_source1->asGroup();
    notnull(group_source1);

    osg::Group* group_source2 = node_source2->asGroup();
    notnull(group_source2);

    int n_children = group_source2->getNumChildren();
    std::cout << "appending " << n_children << " children from \"" << source2 << "\" into data from \"" << source1 << "\"" << std::endl;

    for (int i = 0; i < n_children; i++)
    {
        osg::Node* node = group_source2->getChild(i);
        notnull(node);
        group_source1->addChild(node);

    }
    osgDB::writeNodeFile(*group_source1, dest_filename);
    std::cout << "saved to " << dest_filename << std::endl;

}
