project('Kei Shell', 'cpp',
        default_options: [ 'cpp_std=c++23', 'warning_level=3' ],
        license: 'GPL-3.0-or-later',
        version: '1.0.0-alpha')


add_project_dependencies([
    dependency('boost', modules: [ 'system', 'filesystem' ])
], language: 'cpp')

add_project_arguments([
    '-DAPP_NAME="@0@"'.format(meson.project_name()),
    '-DAPP_VERSION="@0@"'.format(meson.project_version()),
    '-DDEBUG_BUILD=@0@'.format(get_option('buildtype').contains('debug')),
], language: 'cpp')


shell_files = files(
    'src/shell/parser.cc',
)


source_files = files(
    'src/arg_parser.cc',
    'src/exception.cc',
    'src/main.cc',
    'src/utils.cc',
) + shell_files

executable('kesh', source_files,
           include_directories: include_directories('include'))