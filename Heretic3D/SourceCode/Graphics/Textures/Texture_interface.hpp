//#pragma once
//
//#include <vector>
//
//class Model_interface
//{
//public:
//	// Draws the model, and thus all its meshes
//	void Draw(const unsigned int shaderID);
//	std::vector<Mesh> getMesh();
//	std::vector<Texture> getTextures();
//	void setTextures(std::vector<Texture>);
//	void loadModel(string path, string dirr);
//	void setupMeshes();
//private:
//	/*  Model Data  */
//	std::vector<string> texturesStrings;
//	std::vector<Mesh> meshes;
//	std::string dir;
//	std::string directory;
//	std::vector<Texture> textures_loaded;	// Stores all the textures loaded so far, optimization to make sure textures aren't loaded more than once.
//
//	void loadModel(std::string path);
//
//	// Processes a node in a recursive fashion. Processes each individual mesh located at the node and repeats this process on its children nodes (if any).
//	void processNode(aiNode* node, const aiScene* scene);
//
//	Mesh processMesh(aiMesh* mesh, const aiScene* scene);
//
//	// Checks all material textures of a given type and loads the textures if they're not loaded yet.
//	// The required info is returned as a Texture struct.
//	std::vector<Texture> loadMaterialTextures(std::string typeName);
//
//
//	GLuint loadImage(const char* path, std::string directory);
//};
//};