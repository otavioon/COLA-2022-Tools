#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <set>
#include <memory>

struct TestData
{
  int testNum;
  std::string input;
  std::string expectedOutput;
};

struct TestResult
{
  std::string testOutput;
  bool testPassed;
};

void testSolution();
TestResult runTestCase(const TestData& testData);
std::string formatResult(const TestData& testData, const TestResult& testResult);
void solution(std::istream& is, std::ostream& os);

static const bool IS_TESTING = false;

// define test data
static const std::vector<TestData> testDatas = {
  {1, "4 3\n1 2\n2 3\n2 4\n2 10\n1 100\n3 1\n", "100 110 111 110\n"},
  {2, "6 2\n1 2\n1 3\n2 4\n3 6\n2 5\n1 10\n1 10\n", "20 20 20 20 20 20\n"},
};

int main()
{
  if (IS_TESTING)
    testSolution();
  else
    solution(std::cin, std::cout);

  return 0;
}

void testSolution()
{
  for (const auto& testData : testDatas) {
    auto testResult = runTestCase(testData);

    std::cout << formatResult(testData, testResult);
  }
}

TestResult runTestCase(const TestData& testData)
{
    std::istringstream iss {testData.input};
    std::ostringstream oss {};

    solution(iss, oss);

    auto testOutput = oss.str();
    auto testPassed = testData.expectedOutput.compare(testOutput) == 0;
    
    return {testOutput, testPassed};
}

std::string formatResult(const TestData& testData, const TestResult& testResult)
{
  std::ostringstream oss {};

  oss << "Test " << std::setw(2) << testData.testNum << ": "
    << (testResult.testPassed ? "Passed!" : "Failed!") << std::endl;
  
  oss << "\tExpected: " << testData.expectedOutput << "\tActual  : " << testResult.testOutput << std::endl;

  return oss.str();
}

class Node
{
  public:
    Node(int index)
    {
      this->index = index;
    }
    Node* getVertex(int index)
    {
      if (this->index == index)
        return this;
        
      for (auto& child: this->children) {
        Node* vertex = child.getVertex(index);
        if (vertex != nullptr) return vertex;
      }

      return nullptr;
    }
    void addChildren(int index)
    {
      children.emplace_back(index);
    }
    void incrementCounterSubtree(int n)
    {
      this->counter += n;
      for (auto& child: this->children) {
        child.incrementCounterSubtree(n);
      }
    }

    int counter = 0;

  private:
    int index;
    std::vector<Node> children;
};

class Tree
{
  public:
    Tree()
    {
      root = std::make_unique<Node>(1);
    }
    Node* getVertex(int index)
    {
      return root->getVertex(index);
    }
  
    std::unique_ptr<Node> root;
};

// solution to the problem
void solution(std::istream& is, std::ostream& os)
{
  int numVertices, numOperations;
  is >> numVertices >> numOperations;

  auto tree = std::make_unique<Tree>();
  for (auto i = 1; i < numVertices; ++i) {
    int parentIndex, childIndex;
    is >> parentIndex >> childIndex;

    tree->getVertex(parentIndex)->addChildren(childIndex);
  }

  for (auto i = 0; i < numOperations; ++i) {
    int rootIndex, incrementValue;
    is >> rootIndex >> incrementValue;

    tree->getVertex(rootIndex)->incrementCounterSubtree(incrementValue);
  }

  for (auto i = 1; i <= numVertices; ++i) {
    os << tree->getVertex(i)->counter;
    if (i != numVertices) os << " ";
  }
  os << std::endl;
}