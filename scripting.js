const wrapper = document.querySelector('.wrapper');
const loginLink = document.querySelector('.login-link');
const registerLink = document.querySelector('.register-link');
const btnPopup = document.querySelector('.btnLogin-popup');
const iconClose = document.querySelector('.icon-close');
const loginForm = document.querySelector(".login")
registerLink.addEventListener('click', () => {
    loginForm.classList.add('hide');
    wrapper.classList.add('active');
     
});

loginLink.addEventListener('click', () => {
    loginForm.classList.remove('hide');
    wrapper.classList.remove('active');
})

btnPopup.addEventListener('click', () => {
    wrapper.classList.add('active-popup');
});

iconClose.addEventListener('click', () => {
    wrapper.classList.remove('active-popup');

}); 