#include "Number.h"

Number::Number(float width, float height, std::string textureName, std::string shaderName) : Entity(width, height, textureName, shaderName) {

}
void Number::Draw(SpriteRenderer& Renderer) {
	sprite->Draw(Renderer);
}