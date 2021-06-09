#include "pch.h"
#include "CppUnitTest.h"
#include "child.h"
#include "animal.h"
#include "bird.h"
#include "list342.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace program3
{
	int score = 1;
	TEST_CLASS(program3)
	{
	public:
		TEST_METHOD(insertIntoEmptylist_1)
		{
			Child c1("Ann", "Hanlin", 7), c2("Pradnya", "Dhala", 8), c3("Bill", "Vollmann", 13), c4("Cesar", "Ruiz", 6);
			Child c5("Piqi", "Tang", 7), c6("Pete", "Rose", 13), c7("Hank", "Aaron", 3), c8("Madison", "Fife", 7);
			Child c9("Miles", "Davis", 65), c10("John", "Zorn", 4), c11;
			List342<Child> class1, class2, soccer, chess, rockstars, family, santasList;
			Child temp;
			class1.Insert(&c1);
			class1.Insert(&c2);
			class1.Insert(&c3);

			Assert::IsTrue(class1.Peek(c1, temp));
			Assert::IsTrue(class1.Peek(c2, temp));
			Assert::IsTrue(class1.Peek(c3, temp));

			score = score + 4;
		}

		TEST_METHOD(insertEndOfthelist_2)
		{
			Child c1("Ann", "Hanlin", 7), c2("Pradnya", "Dhala", 8), c3("Bill", "Vollmann", 13), c4("Cesar", "Ruiz", 6);
			Child c5("Piqi", "Tang", 7), c6("Pete", "Rose", 13), c7("Hank", "Aaron", 3), c8("Madison", "Fife", 7);
			Child c9("Miles", "Davis", 65), c10("John", "Zorn", 4), c11;
			List342<Child> class1, class2, soccer, chess, rockstars, family, santasList;
			Child temp1, temp2, temp3, temp10;
			class1.Insert(&c1);
			class1.Insert(&c2);
			class1.Insert(&c10);

			ostringstream stream;
			stream << class1;
			Assert::AreEqual((std::string)"PradnyaDhala8AnnHanlin7JohnZorn4", stream.str());
			score = score + 4;

		}

		TEST_METHOD(insertDuplicates_3)
		{
			Child c1("Ann", "Hanlin", 7), c2("Pradnya", "Dhala", 8), c3("Pradnya", "Dhala", 8);
			List342<Child> class1;

			class1.Insert(&c1);
			class1.Insert(&c2);
			class1.Insert(&c3);

			ostringstream stream;
			stream << class1;
			Assert::AreEqual((std::string)"PradnyaDhala8AnnHanlin7", stream.str());
			score = score + 4;
		}

		TEST_METHOD(insertLargeNumber_4)
		{
			int a = 1, b = -1, d = 10000;
			List342<int>numbers;
			numbers.Insert(&a);
			numbers.Insert(&d);
			numbers.Insert(&b);
			ostringstream stream;
			stream << numbers;
			Assert::AreEqual((std::string)"-1110000", stream.str());
			score = score + 4;
		}

		TEST_METHOD(RemoveLastElement_5)
		{
			Child c1("Ann", "Hanlin", 7), c2("Pradnya", "Dhala", 8), c3("Bill", "Vollmann", 13), c11;
			List342<Child>* class1 = new List342<Child>();
			List342<Child>* class2 = new List342<Child>();
			Child temp;
			class1->Insert(&c2);
			class1->Insert(&c3);
			class1->Insert(&c1);
			class1->Remove(c3, c11);
			class2->Insert(&c11);

			ostringstream stream, stream1;
			stream << *class1;
			stream1 << *class2;
			Assert::AreEqual((std::string)"BillVollmann13", stream1.str());
			Assert::AreEqual((std::string)"PradnyaDhala8AnnHanlin7", stream.str());
			score = score + 4;
		}

		TEST_METHOD(RemoveFirstElement_6)
		{
			Child c1("Ann", "Hanlin", 7), c2("Pradnya", "Dhala", 8), c3("Bill", "Vollmann", 13), c11;
			List342<Child>* class1 = new List342<Child>();
			List342<Child>* class2 = new List342<Child>();
			Child temp;
			class1->Insert(&c2);
			class1->Insert(&c3);
			class1->Insert(&c1);
			class1->Remove(c2, c11);
			class2->Insert(&c11);

			ostringstream stream, stream1;
			stream << *class1;
			stream1 << *class2;
			Assert::AreEqual((std::string)"PradnyaDhala8", stream1.str());
			Assert::AreEqual((std::string)"AnnHanlin7BillVollmann13", stream.str());
			score = score + 4;
		}

		TEST_METHOD(peekFirstSecondLast_7)
		{
			Child c1("Ann", "Hanlin", 7), c2("Pradnya", "Dhala", 8), c3("Bill", "Vollmann", 13), c11;
			List342<Child>* class1 = new List342<Child>();

			Child temp;
			class1->Insert(&c2);
			class1->Insert(&c3);
			class1->Insert(&c1);
			class1->Peek(c2, temp);
			Assert::AreEqual(temp.getName(), string("PradnyaDhala"));
			Assert::AreEqual(temp.getAge(), 8);
			class1->Peek(c1, temp);
			Assert::AreEqual(temp.getName(), string("AnnHanlin"));
			Assert::AreEqual(temp.getAge(), 7);
			class1->Peek(c3, temp);
			Assert::AreEqual(temp.getName(), string("BillVollmann"));
			Assert::AreEqual(temp.getAge(), 13);
			score = score + 3;
		}

		TEST_METHOD(peekInaLoop_8)
		{
			Child c1("Ann", "Hanlin", 7), c2("Pradnya", "Dhala", 8), c3("Bill", "Vollmann", 13), c11;
			List342<Child>* class1 = new List342<Child>();


			Child temp;
			class1->Insert(&c2);
			class1->Insert(&c3);
			class1->Insert(&c1);
			int count = 1;
			while (count <= 1000)
			{
				class1->Peek(c2, temp);
				Assert::AreEqual(temp.getName(), string("PradnyaDhala"));
				Assert::AreEqual(temp.getAge(), 8);
				class1->Peek(c1, temp);
				Assert::AreEqual(temp.getName(), string("AnnHanlin"));
				Assert::AreEqual(temp.getAge(), 7);

				count++;

			}
			score = score + 3;
		}

		TEST_METHOD(isempty_9)
		{
			List342<Child>* class1 = new List342<Child>();
			Assert::IsTrue(class1->isEmpty());
			score = score + 3;
		}

		TEST_METHOD(buildInsertDeleteIntClass_10)
		{
			List342<int>* numbers = new List342<int>();

			int a = 4, b = -6, c = -7;
			numbers->BuildList("c:\\test\\ints.txt");
			int temp, temp1;
			numbers->Insert(&a);
			numbers->Insert(&b);
			numbers->Insert(&c);
			Assert::IsTrue(numbers->Peek(a, temp));
			Assert::IsTrue(numbers->Peek(b, temp));
			Assert::IsTrue(numbers->Peek(c, temp));
			numbers->Remove(a, temp);
			Assert::IsFalse(numbers->Peek(a, temp1));
			numbers->Remove(c, temp);
			Assert::IsFalse(numbers->Peek(c, temp1));
			ostringstream stream;
			stream << *numbers;
			Assert::AreEqual((std::string)"-6-1113", stream.str());
			score = score + 3;
		}

		TEST_METHOD(equality_11)
		{
			Child c1("Ann", "Hanlin", 7), c2("Pradnya", "Dhala", 8), c4("Cesar", "Ruiz", 6);
			Child c5("Piqi", "Tang", 7), c6("Pete", "Rose", 13), c7("Hank", "Aaron", 3), c8("Madison", "Fife", 7);
			Child c9("Miles", "Davis", 65), c10("John", "Zorn", 4), c11;
			List342<Child> class1, class2, soccer, chess, rockstars, family, santasList;
			class1.Insert(&c1);
			class1.Insert(&c2);
			class2.Insert(&c1);
			class2.Insert(&c2);
			Assert::IsTrue(class1 == class2);
			class1.Insert(&c4);
			Assert::IsTrue(class1 != class2);
			score = score + 3;
		}

		TEST_METHOD(assignment_12)
		{
			Child c1("Ann", "Hanlin", 7), c2("Pradnya", "Dhala", 8), c4("Cesar", "Ruiz", 6);
			Child c5("Piqi", "Tang", 7), c6("Pete", "Rose", 13), c7("Hank", "Aaron", 3), c8("Madison", "Fife", 7);
			Child c9("Miles", "Davis", 65), c10("John", "Zorn", 4), c11;
			List342<Child> class1, class2, soccer, chess, rockstars, family, santasList;
			Child temp;
			class1.Insert(&c1);
			class1.Insert(&c2);
			class2 = class1;
			Assert::IsTrue(class2.Peek(c1, temp));
			Assert::IsTrue(class2.Peek(c2, temp));
			score = score + 3;
		}


		TEST_METHOD(assignmentToSelf_13)
		{
			Child c1("Ann", "Hanlin", 7), c2("Pradnya", "Dhala", 8), c4("Cesar", "Ruiz", 6);
			Child c5("Piqi", "Tang", 7), c6("Pete", "Rose", 13), c7("Hank", "Aaron", 3), c8("Madison", "Fife", 7);
			Child c9("Miles", "Davis", 65), c10("John", "Zorn", 4), c11;
			List342<Child> class1, class2, soccer, chess, rockstars, family, santasList;
			Child temp;
			class1.Insert(&c1);
			class1.Insert(&c2);
			class1 = class1;

			ostringstream stream;
			stream << class1;

			Assert::AreEqual((std::string)"PradnyaDhala8AnnHanlin7", stream.str());

			score = score + 3;
		}

		TEST_METHOD(plusEqualDifferentList_14)
		{

			Bird b1("swan", 10), b2("parrot", 5), b3("pigeon", 4), b4("duck", 2), temp;

			List342<Bird>thebirds, bird;
			thebirds.Insert(&b1);
			thebirds.Insert(&b2);
			thebirds.Insert(&b3);
			bird.Insert(&b4);
			thebirds += bird;
			Assert::IsTrue(thebirds.Peek(b4, temp));
			score = score + 3;
		}

		TEST_METHOD(plusEqualToSelf_15)
		{
			Bird b1("swan", 10), b2("parrot", 5);

			List342<Bird>thebirds, bird;
			thebirds.Insert(&b1);
			thebirds.Insert(&b2);

			thebirds += thebirds;


			ostringstream stream;
			stream << thebirds;

			Assert::AreEqual((std::string)"parrot5swan10", stream.str());

			score = score + 3;
		}

		TEST_METHOD(plus_16)
		{
			Bird b1("swan", 10), b2("parrot", 5);

			List342<Bird>thebirds, bird, b;
			thebirds.Insert(&b1);
			bird.Insert(&b2);

			b = thebirds + bird;
			ostringstream stream;
			stream << b;
			Assert::AreEqual((std::string)"parrot5swan10", stream.str());

			score = score + 3;
		}

		TEST_METHOD(copyConstructor_17)
		{
			Bird b1("swan", 10), b2("parrot", 5), temp;

			List342<Bird>thebirds;

			thebirds.Insert(&b1);
			thebirds.Insert(&b2);
			List342<Bird>* bird = new List342<Bird>(thebirds);
			Assert::IsTrue(bird->Peek(b1, temp));
			Assert::IsTrue(bird->Peek(b2, temp));
			score = score + 3;
		}

		TEST_METHOD(mergeDifferntLists_18)
		{
			Bird b1("swan", 10), b2("parrot", 5), b3("pigeon", 4), b4("duck", 2), temp;

			List342<Bird> thebirds, bird, t;
			thebirds.Insert(&b1);
			thebirds.Insert(&b2);

			bird.Insert(&b4);
			bird.Merge(thebirds);

			ostringstream stream;
			stream << bird;

			Assert::AreEqual((std::string)"duck2parrot5swan10", stream.str());
			Assert::IsFalse(thebirds.Peek(b1, temp));
			Assert::IsFalse(thebirds.Peek(b2, temp));
			Assert::IsTrue(bird.Peek(b4, temp));
			score = score + 3;
		}

		TEST_METHOD(mergeSameLists_19)
		{
			Bird b1("swan", 10), b2("parrot", 5), b3("pigeon", 4), b4("duck", 2), temp;

			List342<Bird>bird;

			bird.Insert(&b4);
			bird.Merge(bird);

			ostringstream stream;
			stream << bird;

			Assert::AreEqual((std::string)"duck2", stream.str());
			score = score + 3;
		}

		TEST_METHOD(checkBuildlistForChildfile_20)
		{
			List342<Child>* rockstars = new List342<Child>();
			Child p("Thomas", "Paine", 17);
			Child r("Joseph", "Smith", 4);
			Child q("George", "Washington", 12);
			Child pos;
			if ((rockstars->BuildList("C:\\test\\child.txt")))
			{
				Assert::IsTrue(rockstars->Peek(r, pos));
				Assert::IsTrue(rockstars->Peek(p, pos));
				Assert::IsTrue(rockstars->Peek(q, pos));
			}
			score = score + 3;
		}

		TEST_METHOD(checkBuildlistForBirdfile_21)
		{
			List342<Bird>* thebirds = new List342<Bird>();
			Bird p("Eagle", 1);
			Bird r("Warbler", 3);
			Bird q("Tern", 44);
			Bird pos;
			if ((thebirds->BuildList("C:\\test\\birds.txt")))
			{
				Assert::IsTrue(thebirds->Peek(r, pos));
				Assert::IsTrue(thebirds->Peek(p, pos));
				Assert::IsTrue(thebirds->Peek(q, pos));
			}

			score = score + 3;
		}

		TEST_METHOD(checkBuildlistForintFile_22)
		{
			List342<int>* numbers = new List342<int>();
			int p(1);
			int r(-1);
			int q(13);
			int pos;
			if ((numbers->BuildList("C:\\test\\ints.txt")))
			{
				Assert::IsTrue(numbers->Peek(r, pos));
				Assert::IsTrue(numbers->Peek(p, pos));
				Assert::IsTrue(numbers->Peek(q, pos));
			}
			score = score + 3;
		}

		TEST_METHOD(Removebasic_23)

		{
			Child t;

			Child c1("Ann", "Hanlin", 7), c2("Pradnya", "Dhala", 8), c3("Bill", "Vollmann", 13), c11;
			List342<Child>* class1 = new List342<Child>();
			List342<Child>* class2 = new List342<Child>();
			Child temp;
			class1->Insert(&c1);
			class1->Insert(&c2);
			class1->Insert(&c3);
			class1->Remove(c1, c11);
			class2->Insert(&c11);
			ostringstream stream;
			stream << *class2;
			Assert::AreEqual((std::string)"AnnHanlin7", stream.str());
			Assert::IsFalse(class1->Peek(c1, temp));

			score = score + 3;
		}

		TEST_METHOD(buildForDifferntClass_24)
		{
			List342<Animal>* a = new List342<Animal>();
			Animal p("dog", 1);     /////// Similar constructor to Bird
			Animal r("hippo", 3);   /////// Similar calls

			Animal pos;

			if ((a->BuildList("c:\\test\\animal.txt")))
			{
				Assert::IsTrue(a->Peek(r, pos));
				Assert::IsTrue(a->Peek(p, pos));
			}
			score = score + 3;
		}


		TEST_METHOD(DifferentClassInsertDelete_25)
		{
			List342<Animal>* listAnimal = new List342<Animal>();
			Animal d("dog", 1), c("cat", 2);      //////Again, another instance
			listAnimal->Insert(&d);
			listAnimal->Insert(&c);
			Animal temp;

			Assert::IsTrue(listAnimal->Peek(d, temp));
			Assert::IsTrue(listAnimal->Peek(c, temp));
			listAnimal->Remove(d, temp);
			Assert::IsFalse(listAnimal->Peek(d, temp));

			score = score + 3;
		}


		TEST_METHOD(memoryLeaks_26)
		{
			List342<Bird>* birdlist = new List342<Bird>();

			Bird b1("bird1", 1);
			Bird b2("bird2", 2);
			birdlist->Insert(&b1);
			birdlist->Insert(&b2);
			Assert::IsFalse(birdlist->isEmpty());
			birdlist->DeleteList();
			Assert::IsTrue(birdlist->isEmpty());
			score = score + 3;
		}

		TEST_METHOD(zfinalScore)
		{
			score = score / 2;
			Assert::AreEqual(42, score);
		}

	};
	
}
