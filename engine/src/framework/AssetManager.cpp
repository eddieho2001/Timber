#include "framework/AssetManager.h"

namespace timber {
	//IN c++, we must initialize eveything before use
	unique<AssetManager> timber::AssetManager::mPtrAssetManager{ nullptr };

	AssetManager& AssetManager::GetInstance()
	{
		if (mPtrAssetManager == nullptr) {
			//Create AssetManager and transfer the ownership to mPtrAssetManager
			mPtrAssetManager = std::move(unique<AssetManager>{new AssetManager});
		}

		return *mPtrAssetManager;
	}

	shared<sf::Texture> AssetManager::LoadTexture(const std::string& path)
	{
		auto found = mLoadedTextureMap.find(path);//it return iterator 
		if (found != mLoadedTextureMap.end())
		{
			return found->second;
		}

		shared<sf::Texture> newTexture{ new sf::Texture };
		if (newTexture->loadFromFile(mRootDir + path))
		{
			mLoadedTextureMap.insert({ path, newTexture });
			return newTexture;
		}

		return shared<sf::Texture> {nullptr};
	}

	//When external game application construct, it should call AssetManager to set actual path of the game assets
	void AssetManager::SetAssetRootDir(const std::string& p_strDir)
	{
		mRootDir = p_strDir;
	}

	AssetManager::AssetManager()
		: mRootDir{}
	{
	}

}