#include "GridItem.h"

GridItem::GridItem(char symbol) : symbol_(symbol)
{}
char GridItem::getSymbol() const 
{
	return symbol_;
}