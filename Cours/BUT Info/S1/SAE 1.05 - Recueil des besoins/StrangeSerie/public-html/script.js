document.getElementById('menuIcon').addEventListener('click', function () {
    var sidebar = document.getElementById('sidebar');
    if (sidebar.style.left === '-250px') {
        sidebar.style.left = '0';
    } else {
        sidebar.style.left = '-250px';
    }
});

var submenuLinks = document.querySelectorAll('.has-submenu');
submenuLinks.forEach(function (link) {
    link.addEventListener('click', function () {
        link.classList.toggle('active');
        var submenu = link.nextElementSibling;
        if (submenu.style.display === 'block') {
            submenu.style.display = 'none';
        } else {
            submenu.style.display = 'block';
        }
    });
});