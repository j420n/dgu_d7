core = 7.x
api = 2
projects[drupal][type] = "core"
projects[drupal][version] = "7.34"
projects[drupal][patch][] = "https://raw.github.com/datagovuk/dgu_d7/master/patches/menu-undefined-offset-1108314.patch"
projects[drupal][patch][] = "https://raw.github.com/datagovuk/dgu_d7/master/patches/add_get_user_data.patch"
projects[drupal][patch][] = "https://raw.github.com/datagovuk/dgu_d7/master/patches/allow_searching_period-2381971.patch"

projects[dgu][type] = "profile"
projects[dgu][download][type] = "git"
projects[dgu][download][url] = "https://github.com/datagovuk/dgu_d7.git"
projects[dgu][download][branch] = "master"
