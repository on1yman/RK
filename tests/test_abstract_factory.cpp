#include <gtest/gtest.h>
#include "../src/AbstractFactory/Conceptual/main.cc"

TEST(AbstractFactoryTest, ConcreteFactory1Products) {
    ConcreteFactory1 factory;
    AbstractProductA* productA = factory.CreateProductA();
    AbstractProductB* productB = factory.CreateProductB();

    EXPECT_EQ(productA->UsefulFunctionA(), "The result of the product A1.");
    EXPECT_EQ(productB->UsefulFunctionB(), "The result of the product B1.");
    EXPECT_EQ(productB->AnotherUsefulFunctionB(*productA), "The result of the B1 collaborating with ( The result of the product A1. )");

    delete productA;
    delete productB;
}

TEST(AbstractFactoryTest, ConcreteFactory2Products) {
    ConcreteFactory2 factory;
    AbstractProductA* productA = factory.CreateProductA();
    AbstractProductB* productB = factory.CreateProductB();

    EXPECT_EQ(productA->UsefulFunctionA(), "The result of the product A2.");
    EXPECT_EQ(productB->UsefulFunctionB(), "The result of the product B2.");
    EXPECT_EQ(productB->AnotherUsefulFunctionB(*productA), "The result of the B2 collaborating with ( The result of the product A2. )");

    delete productA;
    delete productB;
}
