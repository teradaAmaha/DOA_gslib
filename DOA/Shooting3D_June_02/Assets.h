#ifndef ASSETS_H_
#define ASSETS_H_

enum {
	Mesh_Player,
	Mesh_Enemy,
	Mesh_Asteroid01,
	Mesh_Asteroid02,
	Mesh_Asteroid03,
};

//テクスチャデータ
enum
{
	//2Dスプライト
	Texture_BgTileNebulaGreen,

	//3Dスプライト
	Texture_EffectLazerCyan,
	Texture_EffectLazerOrange,
	Texture_EffectFlash
};

//BGMデータ
enum {
	Music_BackGround
};

//SEデータ
enum {
	Se_ExplosionPlayer,
	Se_ExplosionEnemy,
	Se_ExplosionAsteroid,
	Se_WeaponPlayer,
	Se_WeaponEnemy
};
#endif
