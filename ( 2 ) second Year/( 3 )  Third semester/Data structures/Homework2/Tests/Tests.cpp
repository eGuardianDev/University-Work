

#include "../src/header/Trie.hpp"
#include "../src/header/kheap.hpp"
#include "catch_amalgamated.hpp"

#include <cassert>
#include <sstream>


TEST_CASE( "Testing heap - basic functions")
{
    kHeap heap;

    REQUIRE(heap.isEmpty());
    REQUIRE(heap.Size() == 0);
    REQUIRE(heap.returnCap() == 1);

    Word a1 = Word{"Hello",1,2};
    heap.insert(a1);
    
    REQUIRE_FALSE(heap.isEmpty());
    REQUIRE(heap.Size() == 1);
    REQUIRE(heap.returnCap() == 1);

    Word res = heap.getMin();
    REQUIRE(res == a1);
    
    REQUIRE_FALSE(heap.isEmpty());
    REQUIRE(heap.Size() == 1);
    REQUIRE(heap.returnCap() == 1);

    res = heap.extractMin();
    REQUIRE(res == a1);
    
    REQUIRE(heap.isEmpty());
    REQUIRE(heap.Size() == 0);
    REQUIRE(heap.returnCap() == 1);

    REQUIRE_THROWS(heap.getMin());
    REQUIRE_THROWS(heap.extractMin());

}

TEST_CASE( "Testing heap - more items, all are compared by value")
{
    kHeap heap;

    REQUIRE(heap.isEmpty());
    REQUIRE(heap.Size() == 0);
    REQUIRE(heap.returnCap() == 1);

    Word a1 = Word{"dog",1,0};
    Word a2 = Word{"fish",3,0};
    Word a3 = Word{"cat",2,0};
    heap.insert(a1);

    heap.insert(a2);
    
    REQUIRE(heap.Size() == 2);
    REQUIRE(heap.returnCap() == 3);

    heap.insert(a3);

    REQUIRE(heap.getMin().val == 1);

    REQUIRE(heap.extractMin() == a1);
    REQUIRE(heap.extractMin() == a3);
    REQUIRE(heap.extractMin() == a2);


    REQUIRE(heap.Size() == 0);
    REQUIRE(heap.returnCap() == 3);

    REQUIRE_THROWS(heap.getMin());
    REQUIRE_THROWS(heap.extractMin());


}

TEST_CASE( "Testing kheap - capacity check for diffrent variables ")
{
    kHeap heap1(3);
    REQUIRE(heap1.isEmpty());
    REQUIRE(heap1.Size() == 0);
    REQUIRE(heap1.returnCap() == 1);

    heap1.insert( Word{"dog",1,0});
    REQUIRE_FALSE(heap1.isEmpty());
    REQUIRE(heap1.returnCap() == 1);
    
    heap1.insert( Word{"cat",2,0});
    
    REQUIRE(heap1.returnCap() == 4);
    heap1.insert( Word{"fish",3,0});
    heap1.insert( Word{"capybara",4,0});
    heap1.insert( Word{"rat",4,0});
    heap1.insert( Word{"bear",8,0});
    REQUIRE(heap1.returnCap() == 13);

    kHeap heap2(4);
    REQUIRE(heap2.isEmpty());
    REQUIRE(heap2.Size() == 0);
    REQUIRE(heap2.returnCap() == 1);
    heap2.insert( Word{"cat",2,0});
    heap2.insert( Word{"dog",1,0});

    REQUIRE_FALSE(heap2.isEmpty());
    REQUIRE(heap2.Size() == 2);
    REQUIRE(heap2.returnCap() == 5);

    heap2.insert( Word{"fish",3,0});
    heap2.insert( Word{"capybara",4,0});
    heap2.insert( Word{"rat",4,0});
    heap2.insert( Word{"bear",8,0});
    heap2.insert( Word{"hummingbird",4,0});

    REQUIRE_FALSE(heap2.isEmpty());
    REQUIRE(heap2.Size() == 7);
    REQUIRE(heap2.returnCap() == 21);

}
TEST_CASE( "Testing kheap - basic functions for k == 4 ")
{

    kHeap heap(4);

    Word a1 = Word{"cat",2,0};
    Word a2 = Word{"dog",1,0};
    Word a3 = Word{"fish",3,0};
    Word a4 = Word{"capybara",9,0};
    Word a5 = Word{"rat",4,0};
    Word a6 = Word{"bear",8,0};
    Word a7 = Word{"hummingbird",20,0};
    heap.insert(a1);
    heap.insert(a2);
    heap.insert(a3);
    heap.insert(a4);
    heap.insert(a5);
    heap.insert(a6);
    heap.insert(a7);

    REQUIRE(heap.extractMin() == a2);
    REQUIRE(heap.extractMin() == a1);
    REQUIRE(heap.extractMin() == a3);
    REQUIRE(heap.extractMin() == a5);
    REQUIRE(heap.extractMin() == a6);
    REQUIRE(heap.extractMin() == a4);
    REQUIRE(heap.extractMin() == a7);
    REQUIRE(heap.isEmpty());

}
TEST_CASE( "Testing Trie - basic functions ")
{
    Trie tree;
    tree.append("cat");
    REQUIRE(tree.contains("cat") == 1);
    std::vector<Word> words = tree.getWords();

    REQUIRE(words.size() == 1);
    REQUIRE(words[0].data == "cat");
}
TEST_CASE( "Testing Trie - multple words ")
{
    Trie tree;
    tree.append("cat");
    tree.append("dog");
    tree.append("alalala");
    tree.append("fish");
    tree.append("alabala");
    tree.append("fishy");

    REQUIRE(tree.contains("cat") == 1);
    std::vector<Word> words = tree.getWords();

    std::vector<std::string> checker = {
            "alabala",
            "alalala",
            "cat",
            "dog",
            "fish",
            "fishy"
            };

    for(int i =0;i<checker.size();++i){
        REQUIRE(checker[i] == words[i].data);
    }

}
TEST_CASE( "Testing Trie - check counting")
{
    Trie tree;
    tree.append("cat", 2, false);
    tree.append("dog", 5, false);
    
    tree.append("fish");
    tree.append("fish");
    tree.append("dog");
    tree.append("dog");
    tree.append("dog");



    std::vector<Word> words = tree.getWords();
    Word w;
    w = words[0];
    REQUIRE(w.count == 0);
    REQUIRE(w.val == 2);
    w = words[1];
    REQUIRE(w.count == 3);
    REQUIRE(w.val == 5);
    w = words[2];
    REQUIRE(w.count == 2);
    REQUIRE(w.val == 1);

}
TEST_CASE( "Testing Trie - get word counting")
{
    Trie tree;
    tree.append("cat", 2);
    tree.append("dog", 5);

    REQUIRE(tree.contains("cat"));
    REQUIRE_FALSE(tree.contains("fish"));
    Word w = tree.getWord("cat");

    REQUIRE(w == Word{"cat",2,1});
    REQUIRE_THROWS(tree.getWord("fish"));

}