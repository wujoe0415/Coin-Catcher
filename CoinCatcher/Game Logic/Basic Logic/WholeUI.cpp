#include "WholeUI.h"

WholeUI::WholeUI(float width, float height, std::string textureName, std::string shaderName) : Entity(width, height, textureName, shaderName) {

}
void WholeUI::Draw(SpriteRenderer& Renderer) {
	sprite->Draw(Renderer);
}