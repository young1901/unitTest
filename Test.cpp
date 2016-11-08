#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"

#include "add.h"

void addTest()
{
	ASSERT_EQUAL(2, add(1,0));
}

void runAllTests(int argc, char const *argv[]){
	cute::suite s;
	s.push_back(CUTE(addTest));

	cute::xml_file_opener xmlfile(argc,argv);
	cute::xml_listener<cute::ide_listener<> >  lis(xmlfile.out);
	cute::makeRunner(lis,argc,argv)(s, "AllTests");
}

int main(int argc, char const *argv[]){
    runAllTests(argc,argv);
    return 0;
}



