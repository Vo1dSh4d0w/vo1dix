{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs =
    { self, nixpkgs, ... }@inputs:
    let
      inherit (nixpkgs) lib;

      forAllSystems =
        f:
        lib.genAttrs [
          "x86_64-linux"
          "aarch64-linux"
          "x86_64-darwin"
          "aarch64-darwin"
        ] (system: f nixpkgs.legacyPackages.${system});
    in
    {
      devShells = forAllSystems (pkgs:
        {
          default = pkgs.mkShell {
            buildInputs = with pkgs; [
              pkgsCross.i686-embedded.buildPackages.gcc
              gnumake
              grub2
              xorriso
              qemu
            ];
          };
        }
      );
    };
}
