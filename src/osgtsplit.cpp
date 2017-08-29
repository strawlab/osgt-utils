#include <osgDB/ReadFile>
#include <osgDB/WriteFile>
#include <osgDB/FileUtils>
#include "util.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "need exactly one filename" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    osg::Node* node = osgDB::readNodeFile(filename);
    if (node==NULL) {
        std::cerr << "file not loaded \"" << filename << "\"" << std::endl;
        return 1;
    }

    osg::Group* group = node->asGroup();
    notnull(group);

    int n_children = group->getNumChildren();
    std::cout << "num children: " << n_children << std::endl;

    for (int i = 0; i < n_children; i++)
    {
        osg::Node* this_node = group->getChild(i);

        osg::Group* newgroup = new osg::Group();
        notnull(newgroup);
        newgroup->addChild(this_node);

        std::ostringstream out_filename;
        out_filename << filename << ".part-" << i << ".osgt";
        std::string outfile = out_filename.str();

        std::cout << "  saving child \"" << this_node->getName() << "\" to \"" << outfile << "\"" << std::endl;
        osgDB::writeNodeFile(*newgroup, outfile);
    }

}
