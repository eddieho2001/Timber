#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"

namespace timber {
	class AssetManager {
	public:
		static AssetManager& GetInstance();
		shared<sf::Texture> LoadTexture(const std::string& path);
		void SetAssetRootDir(const std::string& p_strDir);
	protected:
		AssetManager();
	private:
		std::string mRootDir;
		static unique<AssetManager> mPtrAssetManager;
		Dictionary<std::string, shared<sf::Texture>> mLoadedTextureMap;
	};
}