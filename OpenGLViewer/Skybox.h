#pragma once
#include "Buffer.h"
#include "stb_image.h"
#include "Shader.h"
#include <string>
#include "Camera.h"
#include <vector>
#include "SVertex.h"

struct Skybox
{

	void Init();
	void Draw(const SCamera&);

private:
	void CreateBuffers();
	std::vector<SVertex> vertices;
	std::vector<unsigned int> indices;

	SBuffer  m_vertexBuf{}, m_indexBuf{};
	unsigned int m_vao{};
	unsigned int m_modelID{}, m_viewID{}, m_projID{};

	SShader m_shader{};

	unsigned int m_texID{};
	unsigned int m_texUniform{};
	std::string m_path{};
	int m_unit{};

};
