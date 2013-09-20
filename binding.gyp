{
  "targets": [
    {
      "target_name": "zorba",
      "sources": ["src/addon.cpp", "src/execute.cpp"],
      "conditions": [
        [
          "OS==\"linux\"",
          {
            "include_dirs": ["/home/shu/local/include"],
            "cflags": ["-pthread -fPIC -m64 -fexceptions"],
            "cflags_cc": ["-pthread -fPIC -m64 -std=c++11 -fexceptions"],
            "libraries": ["-lzorba_simplestore"],
            "library_dirs": ["/home/shu/local/lib"],
            "ldflags": ["-L/home/shu/local/lib"],
            "link_settings": { "libraries": [""] }
          }
        ],
        ["OS==\"win\"", { }]
      ]
    }
  ]
}
