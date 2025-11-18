{
  description = "Raylib Dev Environment";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let pkgs = import nixpkgs { inherit system; };
      in {
        packages.default = pkgs.stdenv.mkDerivation {
          pname = "raylib-dev-env";
          version = "0.0.1";
          src = ./.;

          nativeBuildInputs = with pkgs; [ cmake pkg-config ];
          buildInputs = with pkgs; [ raylib ];

          buildPhase = ''
            cmake .
            make
          '';

          installPhase = ''
            mkdir -p $out/bin
            cp ./rl $out/bin/
          '';
        };

        devShells.default =
          pkgs.mkShell { packages = with pkgs; [ gcc cmake ]; };
      });
}
