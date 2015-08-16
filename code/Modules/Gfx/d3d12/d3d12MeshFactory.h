#pragma once
//------------------------------------------------------------------------------
/**
    @class Oryol::_priv::d3d12MeshFactory
    @ingroup _priv
    @brief D3D12 implementation of meshFactory
*/
#include "Resource/ResourceState.h"
#include "Gfx/Core/gfxPointers.h"
#include "Gfx/Core/Enums.h"

namespace Oryol {
namespace _priv {

class mesh;

class d3d12MeshFactory {
public:
    /// constructor
    d3d12MeshFactory();
    /// destructor
    ~d3d12MeshFactory();

    /// setup with a pointer to the state wrapper object
    void Setup(const gfxPointers& ptrs);
    /// discard the factory
    void Discard();
    /// return true if the object has been setup
    bool IsValid() const;

    /// setup resource
    ResourceState::Code SetupResource(mesh& mesh);
    /// setup with 'raw' data
    ResourceState::Code SetupResource(mesh& mesh, const void* data, int32 size);
    /// discard the resource
    void DestroyResource(mesh& mesh);

private:
    gfxPointers pointers;
    bool isValid;
};

} // namespace _priv
} // namespace Oryol
