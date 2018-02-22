#include "cg_local.h"
#include "cg_media.h"

void FX_CloneProjectileThink( centity_t *cent, const struct weaponInfo_s *weapon ) {
	vector3 forward;

	if ( VectorNormalize2( &cent->currentState.pos.trDelta, &forward ) == 0.0f )
		forward.z = 1.0f;

	trap->FX_PlayEffectID( media.effects.cloneShotEffect, &cent->lerpOrigin, &forward, -1, -1, qfalse );
}

void FX_CloneAltFireThink( centity_t *cent, const struct weaponInfo_s *weapon ) {
	vector3 forward;

	if ( VectorNormalize2( &cent->currentState.pos.trDelta, &forward ) == 0.0f )
		forward.z = 1.0f;

	trap->FX_PlayEffectID( media.effects.cloneShotEffect, &cent->lerpOrigin, &forward, -1, -1, qfalse );
}

void FX_CloneWeaponHitWall( vector3 *origin, vector3 *normal ) {
	trap->FX_PlayEffectID( media.effects.cloneWallImpactEffect, origin, normal, -1, -1, qfalse );
}

void FX_CloneWeaponHitPlayer( vector3 *origin, vector3 *normal, qboolean humanoid ) {
	trap->FX_PlayEffectID( humanoid ? media.effects.cloneFleshImpactEffect : media.effects.cloneFleshImpactEffect, origin, normal, -1, -1, qfalse );
}
