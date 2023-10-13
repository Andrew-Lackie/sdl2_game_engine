#include <sprites/sprite_definition.h>

size_t Sprite_Define(Sprite_Animation *sprite_animation, const char *url) {

	if(definition_count > MAX_SPRITES) return -1;

	sprite_definitions[definition_count].image = IMG_Load(url);

	if (!sprite_definitions[definition_count].image) return -1;

	sprite_definitions[definition_count].texture = SDL_CreateTextureFromSurface(GLOBAL_DATA(renderer), sprite_definitions[definition_count].image);
	sprite_definitions[definition_count].sprite_animation = sprite_animation;
	sprite_definitions[definition_count].dimensions.w = sprite_definitions[definition_count].image->w / (sprite_definitions[definition_count].sprite_animation->instanceCount * sprite_definitions[definition_count].sprite_animation->frames);
	sprite_definitions[definition_count].dimensions.h = sprite_definitions[definition_count].image->h;
	sprite_definitions[definition_count].pitch = sprite_definitions[definition_count].image->pitch;

	return definition_count++;
}

void Sprites_Init() {

	for (int i = 0; i < MAX_SPRITES; i++) {
		sprite_instances[i].is_active = SDL_FALSE;
	}
}

/* World's longest function definition ever but nevermind... */

size_t Sprite_Create_Instance(int sprite_definition, int initial_anim, int x, int y, float xSpeed, float ySpeed) {

	if (instance_count > MAX_SPRITES) return -1;

	if (sprite_instances[instance_count].is_active == SDL_FALSE) {
		sprite_instances[instance_count].is_active = SDL_TRUE;
		sprite_instances[instance_count].is_visible = SDL_TRUE;
		sprite_instances[instance_count].animation = initial_anim;
		sprite_instances[instance_count].action = 0;
		sprite_instances[instance_count].definition = &sprite_definitions[sprite_definition];

		sprite_instances[instance_count].position.x = x;
		sprite_instances[instance_count].position.y = y;
		sprite_instances[instance_count].position.w = sprite_definitions[sprite_definition].dimensions.w * sprite_definitions[sprite_definition].sprite_animation->scale;
		sprite_instances[instance_count].position.h = sprite_definitions[sprite_definition].dimensions.h * sprite_definitions[sprite_definition].sprite_animation->scale;

		sprite_instances[instance_count].xSpeed = xSpeed;
		sprite_instances[instance_count].ySpeed = ySpeed;

		return instance_count++;
	}

	return -1;
}

void Sprite_Draw_Instances() {

	for (int i = 0; i < MAX_SPRITES; i++) {
		if (sprite_instances[i].is_active == SDL_TRUE) {

			sprite_instances[i].srcrect.x = sprite_instances[i].animation * sprite_instances[i].definition->sprite_animation->frames * sprite_instances[i].definition->dimensions.w;
			sprite_instances[i].srcrect.y = 0;
			sprite_instances[i].srcrect.w = sprite_instances[i].definition->dimensions.w;
			sprite_instances[i].srcrect.h = sprite_instances[i].definition->dimensions.h;

		}
	}
}

void Sprite_Update_Instances() {
	for (size_t i = 0; i < instance_count; i++) {
		Uint32 time = GLOBAL_DATA(curTick) / (sprite_instances[i].definition->sprite_animation->frequency);
		Uint32 count = time % (sprite_instances[i].definition->sprite_animation->frames);
		sprite_instances[i].srcrect.x = count * sprite_instances[i].definition->dimensions.w + (sprite_instances[i].definition->sprite_animation->frames * sprite_instances[i].animation * sprite_instances[i].definition->dimensions.w);

		SDL_RenderCopy(GLOBAL_DATA(renderer), sprite_instances[i].definition->texture, &(sprite_instances[i].srcrect), &(sprite_instances[i].position));
	}
}

void Sprite_Destroy() {
	for (size_t i = 0; i < definition_count; i++) {
		SDL_FreeSurface(sprite_instances[i].definition->image);
		SDL_DestroyTexture(sprite_instances[i].definition->texture);
	}
}
