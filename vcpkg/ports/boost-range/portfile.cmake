# Automatically generated by scripts/boost/generate-ports.ps1

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO boostorg/range
    REF boost-${VERSION}
    SHA512 84386b6a3d41c4213f59f7fe498abcd14bfb0ab0fabfb2515aa083d281bedf36266f40102ae0b0055e8fdb539b2e187da2ce73107e9463a1bcdc2dd4546870dd
    HEAD_REF master
)

set(FEATURE_OPTIONS "")
boost_configure_and_install(
    SOURCE_PATH "${SOURCE_PATH}"
    OPTIONS ${FEATURE_OPTIONS}
)