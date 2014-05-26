#ifndef RENDER_H
#define RENDER_H

#include <vector>
#include "abaci.h"
#include "OVR.h"

namespace gb {
    struct Quad;
}

void RenderInit();

void RenderBegin();
void RenderEnd();

void RenderTextBegin(const Matrixf& projMatrix, const Matrixf& viewMatrix, const Matrixf& modelMatrix);
void RenderText(const std::vector<gb::Quad>& quadVec);
void RenderTextEnd();

void RenderFloor(const Matrixf& projMatrix, const Matrixf& viewMatrix, float height);

void RenderFullScreenQuad(uint32_t texture, float width, float height);
void RenderPostProcessWarp(OVR::Util::Render::StereoConfig& stereoConfig, uint32_t texture, bool left);

#ifdef DEBUG
#define GL_ERROR_CHECK(x) GLErrorCheck(x)
void GLErrorCheck(const char* message);
#else
#define GL_ERROR_CHECK(x)
#endif

#endif  // #define RENDER_H
