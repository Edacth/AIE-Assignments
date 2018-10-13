#pragma once

void product(float a, float b, float& product);
void swap(float &a, float &b);

struct Aussiegochi
{
	float happiness;
	float hunger;
	float thirst;
	float sanity;
};

void feedAussie(Aussiegochi& aus);
void waterAussie(Aussiegochi& aus);
void enterShadowForm(Aussiegochi& aus);
void coddleAussie(Aussiegochi& aus);
void printAussie(Aussiegochi& aus);