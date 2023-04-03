#pragma once

class ClassDefault
{
public:
	// constructer destructer
	ClassDefault();
	~ClassDefault();

	// delete function
	ClassDefault(const ClassDefault& _Ohter) = delete;
	ClassDefault(ClassDefault&& _Ohter) noexcept = delete;
	ClassDefault& operator=(const ClassDefault& _Other) = delete;
	ClassDefault& operator=(ClassDefault&& _Other) noexcept = delete;

protected:

private:

};

