#pragma once

#include <glad\glad.h>
#include <GLFW\glfw3.h>

#include <iostream>
#include <memory>

extern void framebuffer_size_callback(GLFWwindow* window, int width, int height);
extern void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

class Game
{
public:
	Game(unsigned int width=1920, unsigned int height=1080);
	~Game();

	void Init();
	void Update();
	void Render();

	inline unsigned int GetWidth() { return m_width; }
	inline unsigned int GetHeight() { return m_height; }
	inline GLFWwindow* GetWindow() { return m_window; }

private:
	unsigned int m_width;
	unsigned int m_height;

	GLFWwindow* m_window;
};

