#include "llistint.h"
#include "gtest/gtest.h"

class LListIntTest : public testing::Test {
protected:
	// You can remove any or all of the following functions if its body is empty.

	LListIntTest() {
		// You can do set-up work for each test here.
	}

	virtual ~LListIntTest() {
		// You can do clean-up work that doesn't throw exceptions here.		
	
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:
	virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test).
		list.insert(0,2);
		list.insert(1,3);
		list.insert(2,4);
		list2.insert(0,1);
		list2.insert(1,1);
		list2.insert(2,1);
		list2.insert(3,1);

	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).

	}

	// Objects declared here can be used by all tests in the test case.
	LListInt list;
	LListInt list2;
	LListInt list3;
	
};

TEST_F(LListIntTest, Assign) {
	// assign something to itself
	list2 = list2;
	for(int i = 0;i < 4;++i){
		EXPECT_EQ(1,list2.get(i));
	}
	EXPECT_EQ(4,list2.size());
	//normally assign something
	list2 = list;
	for (int i = 0;i<3;++i){
		EXPECT_EQ(list.get(i),list2.get(i));
	}
	EXPECT_EQ(3,list2.size());
	//assign something to a empty list 
	list3 = list;
	for (int i = 0;i<3;++i){
		EXPECT_EQ(list.get(i),list3.get(i));
	}
	EXPECT_EQ(3,list3.size());
	list3.clear();
	list = list3;//assign something empty to the list
	EXPECT_EQ(0,list.size());
	
}

TEST_F(LListIntTest, Plus) {
	list3 = list + list2;//normally add
	for (int i=0;i <3;i++){
		EXPECT_EQ(list.get(i),list3.get(i));
	}
	for (int j =4;j<7;++j){
		EXPECT_EQ(1,list3.get(j));
	}
	EXPECT_EQ(7,list3.size());
	list.clear();
	list3 = list + list2;//add empty list 
	for (int j =1;j<4;++j){
		EXPECT_EQ(1,list3.get(j));
	}
}
TEST_F(LListIntTest, Bracket) {
	EXPECT_EQ(list.get(0),list[0]);
	EXPECT_EQ(list.get(1),list[1]);
	//EXPECT_EQ(2,list.get(1));
	
}

TEST_F(LListIntTest, copyconstuc) {
	LListInt listtemp(list);
	for(int i =0;i< 3;++i){
		EXPECT_EQ(list.get(i),listtemp.get(i));
	}
	list.set(0,1);
	list.set(1,2);
	list.set(2,3);
	EXPECT_EQ(2,listtemp.get(0));
	EXPECT_EQ(3,listtemp.get(1));
	EXPECT_EQ(4,listtemp.get(2));
}
