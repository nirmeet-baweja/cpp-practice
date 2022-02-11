
/**
 * @file multiple-choice-test.cpp
 * @author nirmeet baweja
 * @brief Multiple choice test has several multiple choice questions.
 * Each question can have only one correct answer.
 * Additionally, timed multiple choice test can specify the time
 * allowed for solving each question in the test.
 *
 * The code below satisfies this specification,
 * but the customer complained that the memory usage of the program
 * constantly increases. Fix this problem.
 *
 * @version 0.1
 * @date 2022-02-11
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <iostream>
#include <string>

class MultipleChoiceTest
{
public:
  /**
   * @brief Construct a new Multiple Choice Test object
   *
   * @param questionsCount number of questions in the test
   */
  MultipleChoiceTest(int questionsCount) // constructor
  {
    this->questionsCount = questionsCount;
    answers = new int[questionsCount];
    for (int i = 0; i < questionsCount; i++)
    {
      answers[i] = -1;
    }
  }

  /**
   * @brief Destroy the Multiple Choice Test object
   * adding the virtual keyword stops memory leaks,
   * by invoking the correct destructor
   */
  virtual ~MultipleChoiceTest() // destructor
  {
    // Deallocate the memory that was previously reserved for this string.
    delete[] answers;
  }

  void setAnswer(int questionIndex, int answer)
  {
    answers[questionIndex] = answer;
  }

  int getAnswer(int questionIndex) const
  {
    return answers[questionIndex];
  }

protected:
  int questionsCount;

private:
  int *answers;
};

class TimedMultipleChoiceTest : public MultipleChoiceTest
{
public:
  /**
   * @brief Construct a new Timed Multiple Choice Test object
   *
   * @param questionsCount number of questions in the test
   */
  TimedMultipleChoiceTest(int questionsCount)
      : MultipleChoiceTest(questionsCount) // constructor
  {
    times = new int[questionsCount];
    for (int i = 0; i < questionsCount; i++)
    {
      times[i] = 0;
    }
  }

  /**
   * @brief Destroy the Timed Multiple Choice Test object
   * At code execution-time, the correct destructor is looked up in an object
   * known as a vtable.
   * Hence the destructor associated with derived class will be called prior
   * to a further call to the destructor associated with base class.
   */
  virtual ~TimedMultipleChoiceTest() //destructor
  {
    // Deallocate the memory that was previously reserved for this pointer.
    delete[] times;
  }

  void setTime(int questionIndex, int time)
  {
    times[questionIndex] = time;
  }

  int getTime(int questionIndex) const
  {
    return times[questionIndex];
  }

private:
  int *times;
};

#ifndef RunTests
void executeTest()
{
  MultipleChoiceTest test(5);
  for (int i = 0; i < 5; i++)
  {
    test.setAnswer(i, i);
  }

  for (int i = 0; i < 5; i++)
  {
    std::cout << "Question " << i + 1 << ", correct answer: " << test.getAnswer(i) << "\n";
  }
}

int main()
{
  for (int i = 0; i < 3; i++)
  {
    std::cout << "Test: " << i + 1 << "\n";
    executeTest();
  }
}
#endif